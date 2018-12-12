#include "sqc_zorder_sort.h"

NAMESPACE_SQC

namespace {
    enum sort_order {
        order_same,
        order_desc,
        order_asc,
    };
    
    struct object_info {
    public:
        object_info( sqc_game_object_ptr o ) : obj( o ) {
            sqc_size  size = obj->get_size();
            sqc_point   pos = obj->get_position();
            
            x = pos.x;
            y = pos.y;
            cx = size.cx;
            cy = size.cy;
        }
        
        virtual ~object_info() {
        }
        
        sort_order compare( object_info const &o ) const {
            if (y < o.y + o.cy && x > o.x)          return order_desc;
            if (x + cx > o.x  && y < o.y)           return order_desc;
            if (y + cy > o.y && x+ cx <= o.x )      return order_asc;
            if (x < o.x + o.cx && y >= o.y + o.cy)  return order_asc;
            
            return order_same;
        }
        
        int x, y, cx, cy;
        sqc_game_object_ptr obj;
    };

    typedef std::tr1::shared_ptr<object_info>   object_info_ptr;
    typedef std::list<object_info_ptr>          object_info_list;

    bool compare_center( object_info_ptr o1, object_info_ptr o2 ) {
        return (o1->x * 2 + o1->cx) - (o1->y * 2 + o1->cy) < (o2->x * 2 + o2->cx) - (o2->y * 2 + o2->cy);
    }
}


void zorder_sort( sqc_game_object_list &objects_to_sort ) {
    //BEGIN_PROFILED_AREA( "parse->sort" );
    
    {
        //BEGIN_PROFILED_AREA( "parse->sort2" );
        
        object_info_list    objects, sorted_objects, new_objects;
        
        for( sqc_game_object_list::iterator i = objects_to_sort.begin(); i != objects_to_sort.end(); ++i )  {
            objects.push_back( object_info_ptr( new object_info( *i ) ) );
        }
        
        objects.sort( compare_center );
        
        for( object_info_list::const_iterator i = objects.begin(); i != objects.end(); ++i ) {
            object_info_ptr obj_a( *i );
            object_info_ptr obj_i;
            
            object_info_list::iterator last_below  = sorted_objects.end();
            object_info_list::iterator last_below2 = sorted_objects.end();
            new_objects.clear();
            
            for( object_info_list::iterator j =  sorted_objects.begin(); j != sorted_objects.end(); ++j ) {
                object_info_ptr obj_b( *j );
                
                if( obj_i ) {
                    // если b после c
                    if( obj_b->compare( *obj_i.get() ) == order_desc ) {
                        last_below2 = j;
                    }
                    else {
                        // если а после b
                        if( obj_a->compare( *obj_b.get() ) == order_desc ) {
                            object_info_list::iterator i2 = last_below2;
                            for( ++i2; i2 != j; ) {
                                new_objects.push_back( *i2 );
                                sorted_objects.erase( i2++ );
                            }
                        }
                    }
                }
                else {
                    // если а перед b
                    if( obj_a->compare( *obj_b.get() ) == order_asc ) {
                        last_below  = j;
                        last_below2 = j;
                        
                        obj_i = *j;
                    }
                }
            }
            new_objects.push_back( obj_a );
            
            for( object_info_list::const_reverse_iterator i = new_objects.rbegin(); i != new_objects.rend(); ++i ) {
                sorted_objects.insert( last_below, *i );
            }
        }

        objects_to_sort.clear();
        
        for( object_info_list::const_iterator i = sorted_objects.begin(); i != sorted_objects.end(); ++i ) {
            objects_to_sort.push_back( (*i)->obj );
        }
        
        //END_PROFILED_AREA
    }
    //END_PROFILED_AREA
}



END_NAMESPACE_SQC
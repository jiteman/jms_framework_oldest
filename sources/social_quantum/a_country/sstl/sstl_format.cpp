#include "sstl_format.h"
#include <stdarg.h>

const int init_size = 100;
std::string format(const std::string format_str, ...)
{
	va_list alist;
    std::string s(format_str);
	
    if (format_str.size() == 0) {
    	return "";
    }

	for(int i=0; i < format_str.size(); i++)
    {
        if (s[i] == '@') {
        	s[i] = 's';
        }
    }

    va_start(alist, format_str);

	std::string buffer(init_size, 0);
    int req_sz = 0;
    int res = 0;
    do {
		req_sz = buffer.size() + 1;
        res = vsnprintf(&buffer[0], req_sz, format_str.c_str(), alist);

		if (res < 0) {
			buffer = "";
            break;
		}

		if( res < req_sz ) {
			buffer.resize(res);
            break;
        }
        
        buffer.resize( res );
    	
    } while( true );

    va_end(alist);
    
    return buffer;
}

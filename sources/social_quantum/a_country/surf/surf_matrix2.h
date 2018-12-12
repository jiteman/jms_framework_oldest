#ifndef SURF_MATRIX2_H_INCLUDED
#define SURF_MATRIX2_H_INCLUDED


#include "surf_defs.h"

#include <cmath>

NAMESPACE_SURF


   
  
    /// \brief 2D matrix
    ///
    struct surf_matrix2x2
    {
  
            /// \brief Constructs a 2x2 matrix (uninitialised)
            surf_matrix2x2() { }

            /// \brief Constructs a 2x2 matrix (copied)
            surf_matrix2x2(const surf_matrix2x2 &copy)
            {
                    for (int i=0; i<4; i++)
                            matrix[i] = copy.matrix[i];
            }

          
            /// \brief Constructs a 2x2 matrix (copied from 4 surf_vals)
            explicit surf_matrix2x2(const surf_val *init_matrix)
            {
                    for (int i=0; i<4; i++)
                            matrix[i] = (surf_val) init_matrix[i];
            }

            /// \brief Constructs a 2x2 matrix (copied from specified values)
            surf_matrix2x2(surf_val m00, surf_val m01, surf_val m10, surf_val m11)
            {
                    matrix[0 * 2 + 0] = m00; matrix[0 * 2 + 1] = m01;
                    matrix[1 * 2 + 0] = m10; matrix[1 * 2 + 1] = m11;
            }



            static surf_matrix2x2 null();

            static surf_matrix2x2 identity();

            /// \brief Multiply 2 matrices
            ///
            /// This multiplies the matrix as follows: result = matrix1 * matrix2
            ///
            /// \param matrix_1 = First Matrix to multiply
            /// \param matrix_2 = Second Matrix to multiply
            /// \return The matrix
            static surf_matrix2x2 multiply(const surf_matrix2x2 &matrix_1, const surf_matrix2x2 &matrix_2);

            /// \brief Add 2 matrices
            ///
            /// This adds the matrix as follows: result = matrix1 + matrix2
            ///
            /// \param matrix_1 = First Matrix to add
            /// \param matrix_2 = Second Matrix to add
            /// \return The matrix
            static surf_matrix2x2 add(const surf_matrix2x2 &matrix_1, const surf_matrix2x2 &matrix_2);

            /// \brief Subtract 2 matrices
            ///
            /// This subtract the matrix as follows: result = matrix1 - matrix2
            ///
            /// \param matrix_1 = First Matrix to subtract
            /// \param matrix_2 = Second Matrix to subtract
            /// \return The matrix
            static surf_matrix2x2 subtract(const surf_matrix2x2 &matrix_1, const surf_matrix2x2 &matrix_2);

   
            surf_val matrix[4];

  
            /// \brief Multiply this matrix and a specified matrix.
            ///
            /// This multiplies the matrix as follows: this = mult * this
            ///
            /// \param mult = Matrix to multiply
            ///
            /// \return reference to this object
            surf_matrix2x2 &multiply(const surf_matrix2x2 &mult);

            /// \brief Add this matrix and a specified matrix.
            ///
            /// This adds the matrix as follows: this = add_matrix - this
            ///
            /// \param add_matrix = Matrix to add
            ///
            /// \return reference to this object
            surf_matrix2x2 &add(const surf_matrix2x2 &add_matrix);

            /// \brief Subtract this matrix and a specified matrix.
            ///
            /// This subtracts the matrix as follows: this = subtract_matrix - this
            ///
            /// \param subtract_matrix = Matrix to subtract
            ///
            /// \return reference to this object
            surf_matrix2x2 &subtract(const surf_matrix2x2 &subtract_matrix);

  
   

   
            /// \brief Copy assignment operator.
            surf_matrix2x2 &operator =(const surf_matrix2x2 &copy) { 
				for (size_t i=0;i<2*2;i++) matrix[i]=copy.matrix[i];
				return *this; 
			}

            /// \brief Multiplication operator.
            surf_matrix2x2 operator *(const surf_matrix2x2 &mult) const { surf_matrix2x2 result = *this; result.multiply(mult); return result; }

            /// \brief Multiplication operator.
            surf_matrix2x2& operator *=(const surf_matrix2x2 &mult)  { multiply(mult); return *this; }

            /// \brief Addition operator.
            surf_matrix2x2 operator +(const surf_matrix2x2 &add_matrix) const { surf_matrix2x2 result = *this; result.add(add_matrix); return result; }

            /// \brief Subtract operator.
            surf_matrix2x2 operator -(const surf_matrix2x2 &subtract_matrix) const { surf_matrix2x2 result = *this; result.subtract(subtract_matrix); return result; }

            /// \brief Equality operator.
            bool operator==(const surf_matrix2x2 &other)
            {
                    for (int i=0; i<4; i++)
                            if (matrix[i] != other.matrix[i]) return false;
                    return true;
            }

            /// \brief Not-equal operator.
            bool operator!=(const surf_matrix2x2 &other) { return !((*this) == other); }

  
    private:
    };




    inline surf_point operator * (const surf_point& v, const surf_matrix2x2& m)
    {
            return surf_point(
                    m.matrix[0*2+0]*v.x + m.matrix[0*2+1]*v.y,
                    m.matrix[1*2+0]*v.x + m.matrix[1*2+1]*v.y);
    }

    inline surf_point operator * (const surf_matrix2x2& m, const surf_point& v)
    {
            return surf_point(
                    m.matrix[0*2+0]*v.x + m.matrix[1*2+0]*v.y,
                    m.matrix[0*2+1]*v.x + m.matrix[1*2+1]*v.y);
    }



    /////////////////////////////////////////////////////////////////////////////
   

    inline surf_matrix2x2 surf_matrix2x2::null()
    {
            surf_matrix2x2 m;
			for (size_t i=0;i<4;i++) m.matrix[i]=0.0f;
            return m;
    }

    inline surf_matrix2x2 surf_matrix2x2::identity()
    {
            surf_matrix2x2 m = null();
            m.matrix[0] = 1;
            m.matrix[3] = 1;
            return m;
    }

    inline surf_matrix2x2 surf_matrix2x2::multiply(const surf_matrix2x2 &matrix_1, const surf_matrix2x2 &matrix_2)
    {
            surf_matrix2x2 dest(matrix_2);
            dest.multiply(matrix_1);
            return dest;
    }

    inline surf_matrix2x2 surf_matrix2x2::add(const surf_matrix2x2 &matrix_1, const surf_matrix2x2 &matrix_2)
    {
            surf_matrix2x2 dest(matrix_2);
            dest.add(matrix_1);
            return dest;
    }

    inline surf_matrix2x2 surf_matrix2x2::subtract(const surf_matrix2x2 &matrix_1, const surf_matrix2x2 &matrix_2)
    {
            surf_matrix2x2 dest(matrix_2);
            dest.subtract(matrix_1);
            return dest;
    }

    


    /////////////////////////////////////////////////////////////////////////////
    // surf_matrix2x2 operations:

    inline surf_matrix2x2 &surf_matrix2x2::multiply(const surf_matrix2x2 &mult)
    {
            surf_matrix2x2 result;
            for (int x=0; x<2; x++)
            {
                    for (int y=0; y<2; y++)
                    {
                            result.matrix[x+y*2] =
                                    matrix[0*2 + x]*mult.matrix[y*2 + 0] +
                                    matrix[1*2 + x]*mult.matrix[y*2 + 1];
                    }
            }
            *this = result;
            return *this;
    }

    inline surf_matrix2x2 &surf_matrix2x2::add(const surf_matrix2x2 &add_matrix)
    {
            matrix[(0*2) + 0] += add_matrix.matrix[(0*2) + 0];
            matrix[(0*2) + 1] += add_matrix.matrix[(0*2) + 1];
            matrix[(1*2) + 0] += add_matrix.matrix[(1*2) + 0];
            matrix[(1*2) + 1] += add_matrix.matrix[(1*2) + 1];
            return *this;
    }

    inline surf_matrix2x2 &surf_matrix2x2::subtract(const surf_matrix2x2 &subtract_matrix)
    {
            matrix[(0*2) + 0] = subtract_matrix.matrix[(0*2) + 0] - matrix[(0*2) + 0];
            matrix[(0*2) + 1] = subtract_matrix.matrix[(0*2) + 1] - matrix[(0*2) + 1];
            matrix[(1*2) + 0] = subtract_matrix.matrix[(1*2) + 0] - matrix[(1*2) + 0];
            matrix[(1*2) + 1] = subtract_matrix.matrix[(1*2) + 1] - matrix[(1*2) + 1];
            return *this;
    }

  






END_NAMESPACE_SURF

#endif /*SB_MATRIX2_H_INCLUDED*/

#include <cmath>
#include <stdio.h>

/// @brief Every internal math function and constant used by Corvine. Uses \code <cmath> \endcode from C numerics library.
/// @include <cmath>
/// @author MindFlares
namespace math {

    template<typename T> struct Vector {
        int n;
        T* val;

        Vector(T x, T y){
            val = new T[2];
            val[0] = x;
            val[1] = y;
            n = 2;
        }

        Vector(T x, T y, T z){
            val = new T[3];
            val[0] = x;
            val[1] = y;
            val[2] = z;
            n = 2;
        }

        Vector(T values[]) {
            val = values;

            n = sizeof(values) / sizeof(values[0]);
        }

        bool operator==(Vector const& v){
            if(this->n != v.n) return false;
            for(int i = 0; i < this->n; i++)
                if(this->val[i] != v.val[i]) return false;
            
            return true;
        }
    };

    template<typename T> struct Matrix {
        int m, n;
        T* val;

        Matrix(int m, int n){
            this->m = m;
            this->n = n;

            val = new T[m * n];
        }

        Matrix(T* values, int m, int n){
            Matrix(m, n);

            for(int i = 0; i < m * n; i++)
                val[i] = values[i];
        }

        T at(int row, int col){
            if(row > m || col > n) return NULL;
            return val[row * n + col];
        }

        T set(int row, int col, T value){
            if(row > m || col > n) return NULL;
            val[row * n + col] = value;
            return value;
        }

        bool operator==(const Matrix<T>& A){
            printf("%d == %d, %d == %d\n", this->n, A.n, this->m, A.m);
            if(this->m != A.m || this->n != A.n) return false;
            for(int i = 0; i < this->n * this->m; i++)
                if(this->val[i] != A.val[i]) return false;

            return true;
        }
    };

    const double POSITIVE_INFINITY = 1.0 / 0.0;
    const double NEGATIVE_INFINITY = -1.0 / 0.0;

/// @brief The math constant 𝑒 (Euler's number, the base of the natural logarithm) represented as a \code double\endcode.
    const double E = 2.7182818284590452354;

/// @brief The math constant π (ratio between a circle's circumference to its diameter) represented as a \code double\endcode.
    const double PI = 3.14159265358979323846;

    


}
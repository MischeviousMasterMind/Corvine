#include <cmath>
#include <stdio.h>

/// @brief Every internal math function and constant used by Corvine. Includes \code <cmath> \endcode from C numerics library.
/// @include <cmath>
/// @author MindFlares
namespace math
{

    template <typename T>
    class Vector
    {
    private:
        std::size_t n;
        T* val;

    public:

        Vector(std::size_t dimensions)
        {
            val = new T[dimensions];
            n = dimensions;
        }

        Vector(T x, T y) : Vector(2)
        {
            val[0] = x;
            val[1] = y;
        }

        Vector(T x, T y, T z) : Vector(3)
        {
            val[0] = x;
            val[1] = y;
            val[2] = z;
        }

        Vector(T values[])
        {
            val = values;

            n = sizeof(values) / sizeof(values[0]);
        }

        size_t size() const
        {
            return n;
        }

        T* getArray() const
        {
            return val;
        }

        bool set(size_t indx, T num)
        {
            if(indx >= n) return false;

            val[n] = num;

            return true;
        }

        double norm()
        {
            T sum = 0;

            for(size_t i = 0; i < n; i++)
                sum += val[i] * val[i];
            
            return sqrt(sum);
        }

        Vector& normalize()
        {
            if(norm() <= 0) return *this;

            double norm = this->norm();

            for(size_t i = 0; i < n; i++)
                val[i] /= norm;
            
            return *this;
        }

        template <typename U> Vector<U> getUnitVector()
        {
            Vector<U> unit = (Vector<U>)*this;
            return unit.normalize();
        }

        T operator[](std::size_t idx)
        {
            return this->val[idx];
        }

        const T operator[](std::size_t idx) const
        {
            return this->val[idx];
        }

        template <typename U> operator Vector<U>()
        {
            Vector<U> copy = Vector<U>(n);

            for(size_t i = 0; i < n; i++)
                copy.set(i, (U)val[i]);
            
            return copy;
        }

        template <typename U> Vector operator=(Vector<U> const &v)
        {
            n = v.size();
            val = new T[n];
            
            for(int i = 0; i < n; i++)
                val[i] = (T)v.getArray()[i];

            return *this;
        }

        template <typename U> Vector operator+=(Vector<U> const &v)
        {
            if (this->n != v.n)
                return nullptr;

            for (std::size_t i = 0; i < this->n; i++)
                this->val[i] += v.val[i];

            return *this;
        }

        template <typename U> Vector operator+(Vector<U> const &v)
        {
            if (this->n != v.n)
                return nullptr;

            Vector sum = Vector(this->n);

            for (std::size_t i = 0; i < this->n; i++)
                sum.val[i] = this->val[i] + v.val[i];

            return sum;
        }

        Vector operator+()
        {
            return *this;
        }
        
        template <typename U> Vector operator-=(Vector<U> const &v)
        {
            if (this->n != v.n)
                return nullptr;

            for (std::size_t i = 0; i < this->n; i++)
                this->val[i] -= v.val[i];

            return *this;
        }

        template <typename U> Vector operator-(Vector<U> const &v)
        {
            if (this->n != v.n)
                return nullptr;

            Vector diff = Vector(this->n);

            for (std::size_t i = 0; i < this->n; i++)
                diff.val[i] = this->val[i] - v.val[i];

            return diff;
        }

        Vector operator-()
        {
            Vector neg = Vector(this->n);

            for (std::size_t i = 0; i < this->n; i++)
                neg.val[i] = -this->val[i];

            return neg;
        }

        template <typename U> bool operator==(Vector<U> const &v)
        {
            if (this->n != v.size())
                return false;

            for (std::size_t i = 0; i < this->n; i++)
                if (this->val[i] != v.getArray()[i])
                    return false;

            return true;
        }

        template <typename U> bool operator!=(Vector<U> const &v)
        {
            return !(*this == v);
        }
    };

    template <typename T>
    struct Matrix
    {
        std::size_t m, n;
        T *val;

        Matrix(std::size_t m, std::size_t n)
        {
            this->m = m;
            this->n = n;

            val = new T[m * n];
        }

        Matrix(T *values, std::size_t m, std::size_t n) : Matrix(m, n)
        {
            val = values;

            for (std::size_t i = 0; i < m * n; i++)
                val[i] = values[i];
        }

        T at(std::size_t row, std::size_t col)
        {
            if (row > m || col > n)
                return NULL;
            return val[row * n + col];
        }

        T set(std::size_t row, std::size_t col, T value)
        {
            if (row > m || col > n)
                return NULL;
            val[row * n + col] = value;
            return value;
        }

        bool operator==(const Matrix<T> &A)
        {
            if (this->m != A.m || this->n != A.n)
                return false;
            for (std::size_t i = 0; i < this->n * this->m; i++)
                if (this->val[i] != A.val[i])
                    return false;

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
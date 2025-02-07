#include <cmath>
#include <stdio.h>

/// @brief Every internal math function and constant used by Corvine. Includes \code <cmath> \endcode from C numerics library.
/// @include <cmath>
/// @author MindFlares
namespace corvine
{

    template <typename T>
    class Vector
    {
    private:
        std::size_t n;
        T *val;

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

        Vector(T values[], size_t n) : Vector(n)
        {
            for(int i = 0; i < n; i++)
                val[i] = values[i];
        }

        size_t size() const
        {
            return n;
        }

        T *getArray() const
        {
            return val;
        }

        bool set(size_t indx, T num)
        {
            if (indx >= n)
                return false;

            val[n] = num;

            return true;
        }

        double norm()
        {
            T sum = 0;

            for (size_t i = 0; i < n; i++)
                sum += val[i] * val[i];

            return sqrt(sum);
        }

        Vector &normalize()
        {
            if (norm() <= 0)
                return *this;

            double norm = this->norm();

            for (size_t i = 0; i < n; i++)
                val[i] /= norm;

            return *this;
        }

        template <typename U>
        Vector<U> getUnitVector()
        {
            Vector<U> unit = (Vector<U>)*this;
            return unit.normalize();
        }

        template <typename U> T dot(Vector<U> v)
        {
            if(n != v.size()) return NAN;

            T product = 0;

            for(size_t i = 0; i < n; i++)
                product += (*this)[i] * v[i];
            
            return product;
        }

        template <typename U> Vector cross(Vector<U> v)
        {
            if(n != 3 || v.size() != 3) return nullptr;

            return Vector<T>(
                (T)((*this)[1] * v[2] - (*this)[2] - v[1]),
                (T)((*this)[2] * v[0] - (*this)[0] - v[2]),
                (T)((*this)[0] * v[1] - (*this)[1] - v[0])
            );
        }

        T operator[](std::size_t idx)
        {
            return this->val[idx];
        }

        const T operator[](std::size_t idx) const
        {
            return this->val[idx];
        }

        template <typename U>
        operator Vector<U>()
        {
            Vector<U> copy = Vector<U>(n);

            for (size_t i = 0; i < n; i++)
                copy.set(i, this->val[i]);

            return copy;
        }

        template <typename U>
        Vector operator=(Vector<U> const &v)
        {
            this->n = v.size();
            this->val = new T[n];

            for (int i = 0; i < n; i++)
                this[i] = (T)v[i];

            return *this;
        }

        template <typename U>
        Vector operator+=(Vector<U> const &v)
        {
            if (this->n != v.n)
                return nullptr;

            for (std::size_t i = 0; i < this->n; i++)
                this->val[i] += v.val[i];

            return *this;
        }

        template <typename U>
        Vector operator+(Vector<U> const &v)
        {
            if (this->n != v.n)
                return nullptr;

            Vector res = Vector(this->n);

            for (std::size_t i = 0; i < this->n; i++)
                res.val[i] = this->val[i] + v.val[i];

            return res;
        }

        Vector operator+()
        {
            return *this;
        }

        template <typename U>
        Vector operator-=(Vector<U> const &v)
        {
            if (this->n != v.n)
                return nullptr;

            for (std::size_t i = 0; i < this->n; i++)
                this->val[i] -= v.val[i];

            return *this;
        }

        template <typename U>
        Vector operator-(Vector<U> const &v)
        {
            if (this->n != v.n)
                return nullptr;

            Vector res = Vector(this->n);

            for (std::size_t i = 0; i < this->n; i++)
                res.val[i] = this->val[i] - v.val[i];

            return res;
        }

        Vector operator-()
        {
            Vector opp = Vector(n);

            for (size_t i = 0; i < n; i++)
                opp.val[i] = -this->val[i];

            return opp;
        }

        template<typename U> Vector operator*=(U scalar)
        {
            for(size_t i = 0; i < n; i++)
                this->val[i] *= scalar;
            
            return *this;
        }

        template<typename U> Vector operator*(U scalar)
        {
            Vector res = Vector(n);

            for(size_t i = 0; i < n; i++)
                res.val[i] = this->val[i] * scalar;

            return res;
        }

        template<typename U> Vector operator/=(U scalar)
        {
            for(size_t i = 0; i < n; i++)
                this->val[i] /= scalar;
            
            return *this;
        }

        template<typename U> Vector operator/(U scalar)
        {
            Vector res = Vector(n);

            for(size_t i = 0; i < n; i++)
                res.val[i] = this->val[i] / scalar;

            return res;
        }

        template <typename U>
        bool operator==(Vector<U> const &v)
        {
            if (this->n != v.size())
                return false;

            for (std::size_t i = 0; i < this->n; i++)
                if (this->val[i] != v.getArray()[i])
                    return false;

            return true;
        }

        template <typename U>
        bool operator!=(Vector<U> const &v)
        {
            return !(*this == v);
        }
    };

    template<typename T, typename U> double angleBetween(Vector<T> v1, Vector<U> v2)
    {
        return acos((double)(v1.dot(v2)) / (v1.norm() * v2.norm()));
    }

    template<typename T, typename U> Vector<T> operator*(U scalar, Vector<T> v)
    {
        return v * scalar;
    }

    template <typename T>
    class Matrix
    {
    private:
        std::size_t m, n;
        T *val;

    public:
        Matrix() : Matrix(0, 0) {}

        Matrix(std::size_t m, std::size_t n)
        {
            this->m = m;
            this->n = n;

            val = new T[m * n];
        }

        Matrix(T *values, size_t m, size_t n) : Matrix(m, n)
        {
            val = values;

            for (std::size_t i = 0; i < m * n; i++)
                val[i] = values[i];
        }

        template <typename U> Matrix(Vector<U> arr[], size_t m, size_t n) : Matrix(m, n)
        {
            for(size_t i = 0; i < n; i++)
            {
                for(size_t ii = 0; ii < m; ii++)
                {
                    if(ii < arr[i].size())
                        val[ii * n + i] = (arr[i])[ii];
                    else
                        val[ii * n + i] = 0;
                }
            }
        }

        T at(std::size_t row, std::size_t col)
        {
            if (row > m || col > n)
                return NAN;
            return val[row * n + col];
        }

        T set(std::size_t row, std::size_t col, T value)
        {
            if (row > m || col > n)
                return NAN;
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
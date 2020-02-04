#ifndef MATRIX_MAT_HPP
#define MATRIX_MAT_HPP

#include <iostream>

// Available in all types of builds
// Do not use with heavy calculations
#define ASSERT(expr, msg) { if (!(expr)) { \
    std::cerr << "ASSERTION FAILED: " << msg \
              << "\nSOURCE: " << __FILE__ << ", line " << __LINE__ << std::endl; exit(1); } }

// Active only in debug builds for heavy processing assertions
// Automatically disabled in release builds
#ifndef NDEBUG
#define DBG_ASSERT(expr, msg) ASSERT(expr, msg)
#else
#define DBG_ASSERT(...) ;
#endif

namespace test {

    class mat {
    public:
        // Zero value ctor
        mat(int row_num, int col_num);

        // Initializer list ctor
        mat(std::initializer_list<std::initializer_list<float>> lst);

        // Copy ctor
        mat(const mat &that);

        // Dtor
        virtual ~mat() { delete[] data; }

        int rows() const { return r; }

        int cols() const { return c; }

        float* operator[](int index) const {
            return data + index * c;
        }

        // Copy-assignment
        mat &operator=(const mat &that);

        friend mat operator*(float scalar, const mat &mat_right);
        friend mat operator*(const mat &mat_left, float scalar);
        friend std::ostream &operator<<(std::ostream &os, const mat &m);

    private:
        float *data;
        int r, c;
    };
}

#endif //MATRIX_MAT_HPP

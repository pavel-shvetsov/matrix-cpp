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
#define CREATE_INC count_creations++;
#define DELETE_INC count_deletions++;
#else
#define DBG_ASSERT(...)
#define CREATE_INC
#define DELETE_INC
#endif

namespace test {

    class mat {
    public:
        // Zero value ctor
        mat(int row_num, int col_num);

        // Initializer list ctor
        mat(std::initializer_list<std::initializer_list<float>> lst);
        mat(std::initializer_list<float> lst);

        // Copy ctor
        mat(const mat &that);

        // Move constructor / assignment
        mat(mat&& that) noexcept;
        mat &operator=(mat &&that) noexcept;

        // Dtor
        virtual ~mat() { delete[] data; DELETE_INC}

        int rows() const { return r; }

        int cols() const { return c; }

        // Matrix subscript operator
        float* operator[](int index) const {
            return data + index * c;
        }

        // Copy-assignment
        mat &operator=(const mat &that);

        friend mat operator*(float scalar, const mat &mat_right);
        friend mat operator*(const mat &mat_left, float scalar);
        friend mat operator*(const mat &lhs, const mat &rhs);
        friend mat operator+(const mat &lhs, const mat &rhs);
        friend std::ostream &operator<<(std::ostream &os, const mat &m);

#ifndef NDEBUG
        static unsigned get_creations() { return count_creations; }
        static unsigned get_deletions() { return count_deletions; }
#endif

    protected:
        int r, c;
        float *data;

#ifndef NDEBUG
        static unsigned count_creations;
        static unsigned count_deletions;
#endif
    };

    // Vector class
    class vec : public mat {
        using mat::mat;
    public:
        using mat::operator=;
        float& operator[](int index) {
            ASSERT(index < r * c, "Wrong index for [] operator")
            return data[index];
        }
    };
}

#endif //MATRIX_MAT_HPP

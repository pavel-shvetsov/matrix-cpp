#include <iomanip>
#include <cstring>

#include "mat.hpp"

namespace test {

#ifndef NDEBUG
    unsigned mat::count_creations = 0;
    unsigned mat::count_deletions = 0;
#endif

    mat::mat(int row_num, int col_num) : r(row_num), c(col_num) {
        ASSERT(row_num > 0 && col_num > 0, "Number of Rows and Columns should be positive.")

        data = new float[row_num * col_num](); CREATE_INC
    }

    mat::mat(std::initializer_list<std::initializer_list<float>> lst) {
        ASSERT(lst.size() > 0, "Initialisation list should not be empty")
        auto &l = lst.begin()[0];
        ASSERT(l.size() > 0, "Initialization list should not be empty")
        r = lst.size(), c = l.size();
        data = new float[r * c]; CREATE_INC
        int i = 0, j = 0;
        for (const auto &list_row:lst) {
            j = 0;
            for (const auto &value:list_row) {
                data[i * c + j] = value;
                j++;
            }
            i++;
        }
    }

    mat::mat(std::initializer_list<float> lst) : r(lst.size()), c(1){
        ASSERT(lst.size() > 0, "Initialisation list should not be empty")
        data = new float[r * c]; CREATE_INC
        int i = 0;
        for (const auto &l:lst) {
            data[i] = l;
            i++;
        }
    }

    mat::mat(const mat &that) : r(that.r), c(that.c){
        data = new float[r * c]; CREATE_INC
        memcpy(data, that.data, r * c * sizeof(float));
    }

    mat &mat::operator=(const mat &that) {
        if (this != &that) {
            r = that.r;
            c = that.c;
            delete[] data; DELETE_INC
            data = new float[that.r * that.c]; CREATE_INC
            memcpy(data, that.data, r * c * sizeof(float));
        }
        return *this;
    }

    mat operator*(float scalar, const mat &mat_right) {
        mat mat_new(mat_right);
        for (int i = 0; i < mat_new.rows() * mat_new.cols(); ++i) {
            mat_new.data[i] *= scalar;
        }
        return mat_new;
    }

    mat operator*(const mat &mat_left, float scalar) {
        return scalar * mat_left;
    }

    mat operator*(const mat &lhs, const mat &rhs) {
        ASSERT(lhs.cols() == rhs.rows(),
                "Matrices have wrong dimensions for multiplication")
        mat mat_new(lhs.rows(), rhs.cols());

        for (int i = 0; i < mat_new.rows() * mat_new.cols(); ++i) {
            int row = i / mat_new.cols();
            int col = i % mat_new.cols();
            for (int k = 0; k < lhs.cols(); ++k) {
                mat_new.data[i] += lhs[row][k] * rhs[k][col];
            }
        }

        return mat_new;
    }

    mat operator+(const mat &lhs, const mat &rhs) {
        ASSERT(lhs.rows() == rhs.rows() && lhs.cols() == rhs.cols(),
                "The dimensions of two matrices should be equal for matrix-matrix addition")
        mat new_mat(lhs.rows(), lhs.cols());
        for (int i = 0; i < new_mat.rows() * new_mat.cols(); ++i) {
            new_mat.data[i] = lhs.data[i] + rhs.data[i];
        }
        return new_mat;
    }

    std::ostream &operator<<(std::ostream &os, const mat &m) {
        os << "[" << m.rows() << "x" << m.cols() << "]\n";
        for (int i = 0; i < m.rows() * m.cols(); ++i) {
            if (i > 0 && i % m.cols() == 0) os << "\n";
            os << std::fixed << std::setprecision(2) << std::showpoint << std::setw(10)
               << m.data[i] << " ";
        }
        os << std::endl;
        return os;
    }

    mat::mat(mat &&that) noexcept : r(0), c(0), data(nullptr) {
        r = that.r; c = that.c; data = that.data;
        that.r = 0; that.c = 0; that.data = nullptr;
    }

    mat &mat::operator=(mat &&that) noexcept {
        if (this != &that) {
            delete[] data;
            r = 0; c = 0;
            r = that.r;
            c = that.c;
            data = that.data;
            that.r = 0; that.c = 0; that.data = nullptr;
        }
        return *this;
    }

}
#include <iomanip>
#include <cstring>

#include "mat.hpp"

test::mat::mat(int row_num, int col_num)
        : r(row_num), c(col_num) {
    ASSERT(row_num > 0 && col_num > 0, "Number of Rows and Columns should be positive.")

    data = new float[row_num * col_num];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            data[i * c + j] = 0;
        }
    }
}

test::mat::mat(std::initializer_list<std::initializer_list<float>> lst) {
    ASSERT(lst.size() > 0, "Initialisation list should not be empty")
    auto &l = lst.begin()[0];
    ASSERT(l.size() > 0, "Initialization list should not be empty")
    r = lst.size(), c = l.size();
    data = new float[r * c];
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

test::mat::mat(const test::mat &that) {
    r = that.r;
    c = that.c;
    data = new float[r * c];
    memcpy(data, that.data, r * c * sizeof(float));
}

std::ostream &test::operator<<(std::ostream &os, const test::mat &m) {
    os << "[" << m.rows() << "x" << m.cols() << "]\n";
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.cols(); ++j) {
            os << std::fixed << std::setprecision(2) << m[i][j] << " ";
        }
        os << std::endl;
    }
    return os;;
}

test::mat test::operator*(float scalar, const test::mat &mat_right) {
    test::mat mat_new(mat_right);
    for (int i = 0; i < mat_new.rows() * mat_new.cols(); ++i) {
        mat_new.data[i] *= scalar;
    }
    return mat_new;
}

test::mat test::operator*(const test::mat &mat_left, float scalar) {
    return scalar * mat_left;
}

test::mat &test::mat::operator=(const test::mat &that) {
    if (this != &that) {
        r = that.r; c = that.c;
        delete[] data;
        data = new float[that.r * that.c];
        memcpy(data, that.data, r * c * sizeof(float));
    }
    return *this;
}

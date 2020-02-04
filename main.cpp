#include "mat.hpp"

int main() {
    {
        test::mat A{{1, 0.45},
                    {2, 1.23}};

        test::mat B(A);

        test::mat C = A * B;

        A[1][1] = 0.22;

        B = 2 * B;

        test::vec D{1, 2, 3, 4, 5};
        D[1] = 1.34;

        std::cout << "A:\n" << A << std::endl;
        std::cout << "B:\n" << B << std::endl;
        std::cout << "C:\n" << C << std::endl;
        std::cout << "D:\n" << D << std::endl;
    }

#ifndef NDEBUG
    std::cout << "Creations: " << test::mat::get_creations()
              << " deletions: " << test::mat::get_deletions() << std::endl;
#endif

    return 0;
};

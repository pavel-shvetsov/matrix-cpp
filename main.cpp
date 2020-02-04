#include "mat.hpp"

int main() {
    {
        std::cout << "Initial values" << std::endl;
        test::mat A{{ 8, 1, 2},
                    {-5, 6, 7}};

        test::mat A1{{-12,  4, 0},
                     {  5, -2, 13}};

        test::mat B{{ -5, 1},
                    {  0, 2},
                    {-11, 7}};

        test::vec V{1, 2, 4};

        std::cout << "A:\n" << A << std::endl;
        std::cout << "A1:\n" << A1 << std::endl;
        std::cout << "B:\n" << B << std::endl;
        std::cout << "V:\n" << V << std::endl;

        std::cout << "Mat x Mat: C = A * B" << std::endl;
        test::mat C = A * B;
        std::cout << "Result:\n" << C << std::endl;

        std::cout << "Mat x Vec: D = A * V" << std::endl;
        test::mat D = A * V;
        std::cout << "Result:\n" << D << std::endl;

        std::cout << "Mat + Mat: E = A + A1" << std::endl;
        test::mat E = A + A1;
        std::cout << "Result:\n" << E << std::endl;

        std::cout << "Scalar mult: 2 * A; V * 3" << std::endl;
        A = 2 * A;
        V = V * 3;
        std::cout << "Result:\n" << A << V << std::endl;


    }

#ifndef NDEBUG
    std::cout << "Creations: " << test::mat::get_creations()
              << " deletions: " << test::mat::get_deletions() << std::endl;
#endif

    return 0;
}

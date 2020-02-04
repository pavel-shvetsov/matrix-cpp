#include "mat.hpp"

int main() {

    test::mat m(3, 5);
//    test::mat m({{4, 3, 2}, {2, 0, -1}, {1, 0, -1}, {1, 0, 1}});
//    test::mat m(4, 3);
    test::mat m2 = m;

//    m = m * 2;
    m2 = 2 * m2;

    std::cout << m << std::endl;
    std::cout << m2 << std::endl;


    return 0;
};

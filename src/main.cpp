#include <iostream>

#include "corvinemath.hpp"

#define Matrix corvine::Matrix
#define Vector corvine::Vector

int main()
{

    Vector<float> v1 = Vector<float>(1, 2, 3);
    Vector<float> v2 = Vector<int>(3, 2, 1);

    Vector<float> arr[] = {v1, v2};

    Matrix<float> M = Matrix<float>(arr, 3, 2);

    std::cout << M.at(2, 0) << std::endl;

    return 0;
}
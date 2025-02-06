#include <iostream>

#include "math.hpp"

#define Matrix math::Matrix
#define Vector math::Vector

int main()
{

    Vector<float> v1 = Vector<float>(1, 2, 3);
    Vector<int> v2 = v1;

    std::cout << v1[0] << std::endl;
    std::cout << v2[0] << std::endl;

    if(v1 == v2)
        std::cout << "TRUE!!!" << std::endl;
    else   
        std::cout << "FALSE!!!" << std::endl;

    return 0;
}
#include <iostream>

#include "math.hpp"

int main(){

    int arr[2][2] = {{1, 0}, {0, 1}};
    math::Matrix<int> m1 = math::Matrix<int>((int *)arr, 2, 2);
    math::Matrix<int> m2 = math::Matrix<int>((int *)arr, 2, 2);

    if(m1 == m2)
        std::cout << "True";
    else
        std::cout << "False";

    return 0;
}
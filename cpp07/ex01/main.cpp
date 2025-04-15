#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T x)
{
    std::cout << x << std::endl;
}

void print1(int x)
{
    std::cout << x << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    iter(intArray, intArraySize, print<int>);
    iter(intArray, intArraySize, print1);

    return 0;
}
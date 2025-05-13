#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try {
        std::vector<int>::iterator vecIt = easyfind(vec, 10);
        std::cout << "Found value at position: " << std::distance(vec.begin(), vecIt) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    
    try {
        std::list<int>::iterator lstIt = easyfind(lst, 4);
        std::cout << "Found value in list at position: " << std::distance(lst.begin(), lstIt) << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
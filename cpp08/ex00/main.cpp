#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    // Testing with vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try {
        // Should find 3
        std::vector<int>::iterator vecIt = easyfind(vec, 10);
        std::cout << "Found value at position: " << std::distance(vec.begin(), vecIt) << std::endl;
        
        // Should throw exception (10 not in vector)
        // std::vector<int>::iterator vecIt2 = easyfind(vec, 10);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Testing with list
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    
    try {
        // Should find 4
        std::list<int>::iterator lstIt = easyfind(lst, 4);
        std::cout << "Found value in list at position: " << std::distance(lst.begin(), lstIt) << std::endl;
        
        // Should throw exception (6 not in list)
        // std::list<int>::iterator lstIt2 = easyfind(lst, 6);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
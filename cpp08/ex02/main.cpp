#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    
    std::cout << "Stack contents: ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    for (; it != ite; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

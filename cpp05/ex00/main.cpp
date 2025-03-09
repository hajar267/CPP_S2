#include <iostream>
#include"Bureaucrat.hpp"

int main() {
    // /////////////////////Valid grade
    try {
        Bureaucrat obj1("Hajar", 50);
        std::cout << obj1 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // /////////////////////////Grade too low
    try {
        Bureaucrat obj2("Hajar", 180);
        std::cout << obj2 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // //////////////////////////Grade too high
    try {
        Bureaucrat obj3("Hajar", 0);
        std::cout << obj3 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // ////////////////////////////Increment/Decrement
    try {
        Bureaucrat obj4("Hajar", 2);
        std::cout << "Before increment: " << obj4 << std::endl;
        
        obj4.toIncrement();
        std::cout << "After increment: " << obj4 << std::endl;
        
        obj4.toIncrement();
        std::cout << "This won't be printed" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
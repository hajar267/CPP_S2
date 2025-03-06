#include <iostream>
#include"Bureaucrat.hpp"

// int main(){
//     try{
//         Bureaucrat obj("hajar ", 18);
//         std::cout<<obj<< " :"<<std::endl;
//     }
//     catch(std::exception& e){
//         std::cout<<  e.what() <<std::endl;
//     }
// }


int main() {
    // Test case 1: Valid grade
    try {
        Bureaucrat obj1("Hajar", 50);
        std::cout << obj1 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // Test case 2: Grade too low
    try {
        Bureaucrat obj2("Hajar", 180); // Grade too high (should throw exception)
        std::cout << obj2 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // Test case 3: Grade too high
    try {
        Bureaucrat obj3("Hajar", 0); // Grade too low (should throw exception)
        std::cout << obj3 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // Test case 4: Increment/Decrement
    try {
        Bureaucrat obj4("Hajar", 2);
        std::cout << "Before increment: " << obj4 << std::endl;
        
        obj4.toIncrement();
        std::cout << "After increment: " << obj4 << std::endl;
        
        obj4.toIncrement(); // Will throw exception (grade becomes 0)
        std::cout << "This won't be printed" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
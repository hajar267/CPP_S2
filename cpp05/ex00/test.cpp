// #include <iostream>
// #include <stdexcept>

// class Bureaucrat {
// private:
//     std::string name;
//     int grade;

// public:
//     class GradeTooHighException : public std::exception {
//     public:
//         const char* what() const noexcept override {
//             return "Grade is too high!";
//         }
//     };

//     class GradeTooLowException : public std::exception {
//     public:
//         const char* what() const noexcept override {
//             return "Grade is too low!";
//         }
//     };

//     Bureaucrat(std::string name, int grade) : name(name) {
//         if (grade < 1)
//             throw GradeTooHighException();
//         if (grade > 150)
//             throw GradeTooLowException();
//         this->grade = grade;
//     }

//     void display() const {
//         std::cout << "Bureaucrat " << name << " has grade " << grade << std::endl;
//     }
// };

// int main() {
//     try {
//         Bureaucrat b2("Bob", -1);
//         b2.display();
//         Bureaucrat b1("Alice", 50);
//         b1.display();

//     }
//     catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }
    






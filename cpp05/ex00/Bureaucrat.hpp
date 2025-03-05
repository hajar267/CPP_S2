// #ifndef BUREAUCRAT_HPP
// #define BUREAUCRAT_HPP
// #include<string>


// class Bureaucrat {
//     private:
//         const std::string name;
//         int grade;
//     public:
//         class GradeTooHighException : public std::exception{
//             public:
//             const char *what()const {
//                 return ("higher number");
//             }
//         };
//         class :GradeTooLowException : public std::exception{
//             public:
//             const char *what()const {
//                 return ("lower number");
//             }
//         };
//         Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade) {
//             if (grade < 1){
//                 throw GradeTooHighException();
//             }
//             else if (grade > 150){
//                 throw GradeTooLowException();
//             }   
//         }
//         const std::string getName(return name) const;
//         int getGrade(return grade) const;
//         void toIncrement(){
//             if (grade < 1){
//                 throw GradeTooHighException();
//             }
//             else if (grade > 150){
//                 throw GradeTooLowException();
//             }
//             this->grade--;
//         }
//         void toDecrement(){
//             if (grade < 1){
//                 throw GradeTooHighException();
//             }
//             else if (grade > 150){
//                 throw GradeTooLowException();
//             }
//             this->grade++;
//         }
// };


// #endif

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Nested exception classes
    class GradeTooHighException : public std::exception {
    public:
        // Correct exception specification for C++98
        const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        // Correct exception specification for C++98
        const char* what() const throw() {
            return "Grade is too low!";
        }
    };

    // Constructor
    Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
        if (grade < 1) {
            throw GradeTooHighException();
        }
        if (grade > 150) {
            throw GradeTooLowException();
        }
    }

    // Getters
    std::string getName() const {
        return name;
    }

    int getGrade() const {
        return grade;
    }

    // Grade increment
    void toIncrement() {
        if (grade - 1 < 1) {
            throw GradeTooHighException();
        }
        grade--;
    }

    // Grade decrement
    void toDecrement() {
        if (grade + 1 > 150) {
            throw GradeTooLowException();
        }
        grade++;
    }
};

#endif // BUREAUCRAT_HPP
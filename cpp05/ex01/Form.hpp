#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration to avoid circular dependency

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    // Exception Classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Form grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Form grade is too low!";
        }
    };

    // Constructor
    Form(const std::string& name, int gradeToSign, int gradeToExecute);

    // Getters
    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Form signing method
    void beSigned(const Bureaucrat& bureaucrat);

    // Insertion operator overload (friend function)
    friend std::ostream& operator<<(std::ostream& os, const Form& form);
};

#endif // FORM_HPP
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

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
    void signForm(Form& form) {
    try {
        // Attempt to sign the form
        form.beSigned(*this);
        
        // If successful, print success message
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const Form::GradeTooLowException& e) {
        // If signing fails, print failure message
        std::cout << name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
};

#endif // BUREAUCRAT_HPP
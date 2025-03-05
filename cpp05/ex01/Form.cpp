#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Form; // Forward declaration

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Nested exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too low!";
        }
    };

    // Constructor
    Bureaucrat(const std::string& name, int grade);

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade manipulation methods
    void incrementGrade();
    void decrementGrade();

    // Form signing method (declaration)
    void signForm(Form& form);
};

#endif // BUREAUCRAT_HPP
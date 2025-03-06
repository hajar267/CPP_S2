#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;


class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    class GradeTooHighException : public std::exception{
        public:
        const char *what()const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
        const char *what()const throw();
    };
    Form(std::string _name, int signgrade, int execgrade);
    const std::string getName(void) const;
    bool IsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &object);


#endif
#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>

class Bureaucrat;


class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

protected:
    virtual void executeFormAction(void) const = 0;

public:
    class GradeTooHighException : public std::exception{
        public:
        const char *what()const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
        const char *what()const throw();
    };
    AForm(std::string _name, int signgrade, int execgrade);
    AForm(const AForm &object);
    AForm &operator=(const AForm &object);
    AForm();
    const std::string getName(void) const;
    bool IsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    void beSigned(Bureaucrat &bureaucrat);
    void execute(Bureaucrat const & executor) const;
    virtual ~AForm();
};

std::ostream &operator<<(std::ostream &out, const AForm &object);

#endif
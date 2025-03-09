
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include<string>
#include<iostream>
#include<stdexcept>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        class GradeTooHighException : public std::exception{
            public:
            const char *what()const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            const char *what()const throw();
        };
        Bureaucrat();
        Bureaucrat(const std::string _name, int _grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &object);
        Bureaucrat &operator=(const Bureaucrat &object);
        std::string getName(void) const;
        int getGrade(void) const;
        void toIncrement(void);
        void toDecrement(void);
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &object);

#endif
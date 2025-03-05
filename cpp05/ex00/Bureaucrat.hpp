#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include<string>


class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        class GradeTooHighException : public std::exception{
            const char *what()const {
                return ("higher number");
            }
        };
        class :GradeTooLowException : public std::exception{
            const char *what()const {
                return ("lower number");
            }
        };
        Bureaucrat(const std::string _name, int _grade) : name(_name), _grade(grade) {
            if (grade < 1){
                throw GradeTooHighException();
            }
            else if (grade > 150){
                throw GradeTooLowException();
            }   
        }
        const std::string getName(return name);
        int getGrade(return grade);
        void toIncrement(){
            if (grade < 1){
                throw GradeTooHighException();
            }
            else if (grade > 150){
                throw GradeTooLowException();
            }
            this->grade--;
        }
        void toDecrement(){
            if (grade < 1){
                throw GradeTooHighException();
            }
            else if (grade > 150){
                throw GradeTooLowException();
            }
            this->grade++;
        }
};


#endif
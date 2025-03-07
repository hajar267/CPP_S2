#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name) {
        if (_grade < 1){
            throw GradeTooHighException();
        }
        else if (_grade > 150){
            throw GradeTooLowException();
        }
        _grade = grade;
    }

std::string Bureaucrat::getName(void) const{return name;}
int Bureaucrat::getGrade(void) const{return grade;}
void Bureaucrat::toIncrement(){
    if (grade < 1){
        throw GradeTooHighException();
    }
    this->grade--;
}
void Bureaucrat::toDecrement(){
    if (grade > 150){
        throw GradeTooLowException();
    }
    this->grade++;
}

const char *Bureaucrat::GradeTooLowException::what()const throw(){
    return ("lower number");
}

const char *Bureaucrat::GradeTooHighException::what()const throw(){
    return ("higher number");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &object) {
out << object.getName() << ", bureaucrat grade " << object.getGrade();
return out;
}
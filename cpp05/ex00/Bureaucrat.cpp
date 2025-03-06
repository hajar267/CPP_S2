#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade) {
        if (grade < 1){
            throw GradeTooHighException();
        }
        else if (grade > 150){
            throw GradeTooLowException();
        }   
    }

std::string Bureaucrat::getName(void) const{return name;}
int Bureaucrat::getGrade(void) const{return grade;}
void Bureaucrat::toIncrement(){
    this->grade--;
    if (grade < 1){
        throw GradeTooHighException();
    }
}
void Bureaucrat::toDecrement(){
    this->grade++;
    if (grade > 150){
        throw GradeTooLowException();
    }
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
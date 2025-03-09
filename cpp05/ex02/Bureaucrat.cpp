#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade) {
        if (grade < 1){
            throw GradeTooHighException();
        }
        else if (grade > 150){
            throw GradeTooLowException();
        }
    }

Bureaucrat::Bureaucrat(const Bureaucrat &object){*this = object;}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &object){   grade = object.grade;    return *this;}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat() : name("default"), grade(1) {}

std::string Bureaucrat::getName(void) const{return name;}
int Bureaucrat::getGrade(void) const{return grade;}
void Bureaucrat::toIncrement(){
    if (grade - 1< 1){
        throw GradeTooHighException();
    }
    this->grade--;
}
void Bureaucrat::toDecrement(){
    if (grade + 1> 150){
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

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    } 
    catch (AForm::GradeTooLowException &e) {
        std::cout << *this << " couldn't sign " << form 
                  << " because grade too low" << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form){
    try{
    form.execute(*this);
    std::cout<< *this <<" executed "<<form<<std::endl;
    }
    catch(const std::exception &e){
        std::cout<<"Error bureaucrat not executed because "<< e.what()<<std::endl;
    }
}

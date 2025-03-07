#include"Form.hpp"
#include"Bureaucrat.hpp"


const std::string Form::getName(void) const{
    return (name);
}
bool Form::IsSigned(void) const{
    return (isSigned);
}
int Form::getGradeToSign(void) const{
    return (gradeToSign);
}
int Form::getGradeToExecute(void)const {
    return (gradeToExecute);
}

const char *Form::GradeTooLowException::what()const throw(){
    return ("lower number");
}

const char *Form::GradeTooHighException::what()const throw(){
    return ("higher number");
}

std::ostream &operator<<(std::ostream &out,  const Form &object) {
out << object.getName() << ", sign grade " << object.getGradeToSign() << ", execute grade "<< object.getGradeToExecute();
return out;
}

Form::Form(std::string _name, int signgrade, int execgrade): name(_name),isSigned(false), gradeToSign(signgrade)  ,gradeToExecute(execgrade) {
if (gradeToSign < 1 || gradeToExecute < 1){
    throw GradeTooHighException();
}
else if (gradeToSign > 150 || gradeToExecute > 150){
    throw GradeTooLowException();
}   
}

void Form::beSigned(Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() <= gradeToSign){ isSigned = true;}
    else if(bureaucrat.getGrade() >= 150) {
        throw (GradeTooLowException());
    }
}


#include"AForm.hpp"
#include"Bureaucrat.hpp"

const std::string AForm::getName(void) const{
    return (name);
}
bool AForm::IsSigned(void) const{
    return (isSigned);
}
int AForm::getGradeToSign(void) const{
    return (gradeToSign);
}
int AForm::getGradeToExecute(void)const {
    return (gradeToExecute);
}

const char *AForm::GradeTooLowException::what()const throw(){
    return ("lower number");
}

const char *AForm::GradeTooHighException::what()const throw(){
    return ("higher number");
}

std::ostream &operator<<(std::ostream &out,  const AForm &object) {
out << object.getName() << ", sign grade " << object.getGradeToSign() << ", execute grade "<< object.getGradeToExecute();
return out;
}

AForm::AForm(std::string _name, int signgrade, int execgrade): name(_name),isSigned(false), gradeToSign(signgrade)  ,gradeToExecute(execgrade) {
if (gradeToSign < 1 || gradeToExecute < 1){
    throw GradeTooHighException();
}
else if (gradeToSign > 150 || gradeToExecute > 150){
    throw GradeTooLowException();
}   
}

void AForm::beSigned(Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() <= gradeToSign){ isSigned = true;}
    else {
        throw (GradeTooLowException());
    }
}

void AForm::execute(Bureaucrat const & executor) const{
    if (!isSigned || executor.getGrade() >= gradeToExecute){
        throw (GradeTooLowException());
    }
    executeFormAction();
}

AForm::~AForm(){};

AForm::AForm(const AForm &object): name(object.name), isSigned(object.isSigned), gradeToSign(object.gradeToSign), gradeToExecute(object.gradeToExecute){
}

AForm &AForm::operator=(const AForm &object){
    isSigned = object.isSigned;
    return *this;
}

AForm::AForm() : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}




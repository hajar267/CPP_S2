#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("", 25, 5) , target(_target){}

void PresidentialPardonForm::executeFormAction(void)const{
    std::cout<< target << "has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &object): AForm(object), target(object.target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &object){
    target = object.target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("", 25, 5), target("default"){}

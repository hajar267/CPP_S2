#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("", 25, 5) , target(_target){}

void PresidentialPardonForm::executeFormAction(void) const{
    std::cout<< target << "has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

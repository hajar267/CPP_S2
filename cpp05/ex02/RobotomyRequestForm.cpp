#include "RobotomyRequestForm.hpp"
#include<cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("", 72, 45),  target(_target) {}

void RobotomyRequestForm::executeFormAction(void) const{
    std::cout<<" *** drilling noises ***"<<std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy of " << target << " has failed!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &object): AForm(object), target(object.target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &object){
    target = object.target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("", 72, 45), target("default"){}


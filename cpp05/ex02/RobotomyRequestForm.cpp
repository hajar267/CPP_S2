#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("", 72, 45),  target(_target) {}

void RobotomyRequestForm::executeFormAction(void){
    std::cout<<" *** drilling noises ***"<<std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy of " << target << " has failed!" << std::endl;
}
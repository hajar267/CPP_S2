#ifndef  RobotomyRequestForm_HPP
#define  RobotomyRequestForm_HPP
#include "AForm.hpp"


class  RobotomyRequestForm : public AForm{
private:
    std::string target;
public:
    RobotomyRequestForm(std::string target);
    void executeFormAction(void) const;
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &object);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &object);
    RobotomyRequestForm();
    
};


#endif 
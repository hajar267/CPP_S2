#ifndef  PresidentialPardonForm_HPP
#define  PresidentialPardonForm_HPP
#include "AForm.hpp"


class  PresidentialPardonForm : public AForm{
private:
    std::string target;
public:
    PresidentialPardonForm(std::string target);
    void executeFormAction(void) const;
};


#endif
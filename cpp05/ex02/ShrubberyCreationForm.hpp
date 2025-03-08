#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP
#include "AForm.hpp"
#include<fstream>


class ShrubberyCreationForm : public AForm{
private:
    std::string target;
public:
    ShrubberyCreationForm(std::string target);
    void executeFormAction(void) const;
};


#endif
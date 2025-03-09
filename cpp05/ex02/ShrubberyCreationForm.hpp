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
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &object);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &object);
    ShrubberyCreationForm();
};


#endif
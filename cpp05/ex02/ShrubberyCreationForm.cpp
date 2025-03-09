#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("",145, 137), target(_target){}

void ShrubberyCreationForm::executeFormAction() const{
    std::string file = target+"_shrubbery";
    std::ofstream writing(file.c_str());
    if(!writing){std::cerr << "Error opening" <<std::endl;  return ;}
    writing << "    #    \n   ###   \n  #####  \n ####### \n   ###   "<<std::endl;
    writing.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &object): AForm(object), target(object.target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &object){
    target = object.target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("",145, 137), target("default"){}

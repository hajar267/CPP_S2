#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("",145, 137), target(_target){}

void ShrubberyCreationForm::executeFormAction(){
    std::string file = target+"_shrubbery";
    std::ofstream writing(file.c_str());
    if(!file){std::cerr << "Error opening" <<std::endl;  return 1;}
    writing << "    #    \n   ###   \n  #####  \n ####### \n   ###   "<<std::endl;
    writing.close();
}

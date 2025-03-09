#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::createShrubberyForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            AForm* form = NULL;
            switch (i){
                case 0:
                    form = createShrubberyForm(target);
                    break;
                case 1:
                    form = createRobotomyForm(target);
                    break;
                case 2:
                    form = createPresidentialForm(target);
                    break;
            }
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    std::cout << "Intern cannot create form: Unknown form type \"" << formName << "\"" << std::endl;
    return NULL;
}
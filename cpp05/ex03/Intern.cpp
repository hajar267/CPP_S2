// Intern.cpp
#include "Intern.hpp"


Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
    // Nothing to copy since Intern has no attributes
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
    // Define form types
    static const std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    // Find the matching form type
    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            Form* form = NULL;
            
            // Create the appropriate form based on index
            if (i == 0)
                form = createShrubberyForm(target);
            else if (i == 1)
                form = createRobotomyForm(target);
            else if (i == 2)
                form = createPresidentialForm(target);
                
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    // Form not found
    std::cout << "Intern cannot create form: Unknown form type \"" << formName << "\"" << std::endl;
    return NULL;
}
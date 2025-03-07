// Intern.hpp
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);
    
    AForm* makeForm(const std::string& formName, const std::string& target) const;
    
private:
    // Individual form creation methods
    AForm* createShrubberyForm(const std::string& target) const;
    AForm* createRobotomyForm(const std::string& target) const;
    AForm* createPresidentialForm(const std::string& target) const;
};

#endif
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bob("Bob", 31);
    RobotomyRequestForm form("Alice");

    bob.signForm(form);
    bob.executeForm(form);

    return 0;
}

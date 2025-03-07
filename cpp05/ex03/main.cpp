#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
AForm* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
std::cout << *rrf << std::endl;
    return 0;
}

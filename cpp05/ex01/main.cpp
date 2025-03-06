// Example usage
#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
    try {
        Bureaucrat bob("Bob", 180);
        Form taxForm("Tax Form", 75, 100);

        bob.signForm(taxForm);

        std::cout << taxForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
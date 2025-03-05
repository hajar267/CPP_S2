// Example usage
#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Form", 75, 100);

        // Attempt to sign the form
        bob.signForm(taxForm);

        // Print form details
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
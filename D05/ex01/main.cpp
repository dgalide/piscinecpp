#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form;
class Bureaucrat;

int main(void)
{
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("alice", 150);
    Form        f1("form 1", 1, 10);

    try {
        alice.signForm(f1);
    } catch (Bureaucrat::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        bob.signForm(f1);
    } catch (Bureaucrat::GradeTooLowException e) {
        std::cout << e.what() << std::endl;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
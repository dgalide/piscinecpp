#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("b1");
    Bureaucrat b2("b2");

    try {
        std::cout << b1;
        b1 += 1000;
    } catch (Bureaucrat::GradeTooHighException e) {
        std::cout << std::string(e.what()) << std::endl;
    }

    try {
        std::cout << b1;
        b1 -= 1000;
    } catch (Bureaucrat::GradeTooLowException e) {
        std::cout << std::string(e.what()) << std::endl;
    }
    return 0;
}
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;
class Bureaucrat;

int main(void)
{

    PresidentialPardonForm      r("target");
    RobotomyRequestForm         s("target");
    ShrubberyCreationForm       p("target");

    Bureaucrat bob("Bob", 150);
    Bureaucrat alice("Alice", 1);

    std::cout << p;
    std::cout << r;
    std::cout << s;

    std::cout << bob;
    std::cout << alice;

    try {
        bob.signForm(p);
    } catch (Form::alreadySignedException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (Form::notSignedException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (std::exception e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    }

    try {
        alice.signForm(p);
    } catch (Form::alreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::notSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }

    try {
        bob.executeForm(p);
    } catch (Form::alreadySignedException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (Form::notSignedException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (std::exception e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    }

    try {
        alice.executeForm(p);
    } catch (Form::alreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::notSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }

    std::cout << p;
    return 0;
}
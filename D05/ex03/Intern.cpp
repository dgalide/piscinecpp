#include "Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(Intern &ref) {
    (void)ref;
}

Intern      &Intern::operator=(Intern &ref) {
    (void)ref;
    return *this;
}

Form        *Intern::makeForm(std::string formType, std::string target) {
    Form    *n;

    n = (formType == "robotomy") ? (Form *)(new RobotomyRequestForm(target))
        : (formType == "president") ? (Form *)(new PresidentialPardonForm(target))
        : (formType == "shrubbery") ? (Form *)(new ShrubberyCreationForm(target))
        : NULL;

    return n;
}
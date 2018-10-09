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

    if (!n)
        throw Intern::FormNotExist();

    return n;
}

/**
 * Exceptions
 */

Intern::FormNotExist::~FormNotExist(void) throw() {}
Intern::FormNotExist::FormNotExist(void) {}
Intern::FormNotExist::FormNotExist(FormNotExist const &e) {
    (void)e;
}

Intern::FormNotExist &Intern::FormNotExist::operator=(FormNotExist const &e) {
    (void)e;
    return *this;
}

const char          *Intern::FormNotExist::what() const throw() {
    return ("Form Does Not Exist... existing forms -> 'president,shrubbery,robotomy'");
}
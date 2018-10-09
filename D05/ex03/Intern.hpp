#ifndef INTERN_HPP
 #define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

    public:

        Intern(void);
        ~Intern(void);
        Intern(Intern &ref);
        Intern &operator=(Intern &ref);

        Form *makeForm(std::string name, std::string target);
};

#endif
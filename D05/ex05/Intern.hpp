#ifndef INTERN_HPP
 #define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

    public:

        class FormNotExist: public std::exception {
        
            public:
                FormNotExist(void);
                FormNotExist(FormNotExist const &ref);
                FormNotExist &operator=(FormNotExist const &ref);
                virtual ~FormNotExist(void) throw();
                virtual const char* what() const throw();
         };

        Intern(void);
        ~Intern(void);
        Intern(Intern &ref);
        Intern &operator=(Intern &ref);

        Form *makeForm(std::string name, std::string target);
};

#endif
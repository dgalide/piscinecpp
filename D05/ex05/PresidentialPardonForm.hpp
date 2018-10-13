#ifndef PRESIDENTIALPARDONFORM_HPP
 #define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>

class Form;

class PresidentialPardonForm: public Form {

    public:

        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm &ref);
        ~PresidentialPardonForm(void);

        void                action(void);

    private:

        // Avoid Default Constructor
        PresidentialPardonForm(void);
};

#endif
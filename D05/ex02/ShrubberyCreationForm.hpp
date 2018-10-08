#ifndef SHRUBBERYCREATIONFORM_HPP
 #define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <fstream>

class Form;

class ShrubberyCreationForm: public Form {

    public:

        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm &ref);
        ~ShrubberyCreationForm(void);

        void                action(void);

    private:

        // Avoid Default Constructor
        ShrubberyCreationForm(void);
};

#endif
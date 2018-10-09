#ifndef ROBOTOMYREQUESTFORM_HPP
 #define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>

class Form;

class RobotomyRequestForm: public Form {

    public:

        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm &ref);
        ~RobotomyRequestForm(void);

        virtual void                action(void);

    private:

        // Avoid Default Constructor
        RobotomyRequestForm(void);
};

#endif
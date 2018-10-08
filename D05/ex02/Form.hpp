#ifndef FORM_HPP
 #define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    public:

        /**
         * Exceptions
         */
        class GradeTooHighException: public std::exception {
        
            public:
                virtual const char* what() const throw();
         };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        /**
         * Constructor / Destructor
         */
        Form(std::string name, int signGrade, int execGrade, std::string target);
        Form(Form &ref);
        ~Form(void);

        /**
         * Getters
         */
        std::string         getName(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        bool                getSigned(void) const;
        std::string         getTarget(void) const;

        /**
         * Method
         */
        void                beSigned(Bureaucrat &ref);

    
    private:

        /**
         * Private Properties
         */
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           execGrade;
        std::string         target;

        // Avoid default constructor
        Form(void);
};

std::ostream        &operator<<(std::ostream &stream ,Form &ref);

#endif
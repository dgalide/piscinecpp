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
                GradeTooHighException(void);
                GradeTooHighException(GradeTooHighException const &ref);
                GradeTooHighException &operator=(GradeTooHighException const &ref);
                virtual ~GradeTooHighException(void) throw();
                virtual const char* what() const throw();
         };

        class GradeTooLowException: public std::exception {
            public:
                GradeTooLowException(void);
                GradeTooLowException(GradeTooLowException const &ref);
                GradeTooLowException &operator=(GradeTooLowException const &e);
                virtual ~GradeTooLowException(void) throw();
                virtual const char* what() const throw();
                
        };

        /**
         * Constructor / Destructor
         */
        Form(std::string name, int signGrade, int execGrade);
        Form(Form &ref);
        ~Form(void);

        /**
         * Getters
         */
        std::string         getName(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        bool                getSigned(void) const;

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

        // Avoid default constructor
        Form(void);
};

std::ostream        &operator<<(std::ostream &stream ,Form &ref);

#endif
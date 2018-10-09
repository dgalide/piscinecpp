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

        class notSignedException: public std::exception {
            public:
                notSignedException(void);
                notSignedException(notSignedException const &ref);
                notSignedException &operator=(notSignedException const &ref);
                virtual ~notSignedException(void) throw();
                virtual const char* what() const throw();
                
        };

        class alreadySignedException: public std::exception {
            public:
                alreadySignedException(void);
                alreadySignedException(alreadySignedException const &ref);
                alreadySignedException &operator=(alreadySignedException const &ref);
                virtual ~alreadySignedException(void) throw();
                virtual const char* what() const throw();
        };

        /**
         * Constructor / Destructor
         */
        Form(std::string name, int signGrade, int execGrade, std::string target);
        Form(Form &ref);
        Form    &operator=(Form &f);
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
        void                execute(Bureaucrat &b);
        virtual void        action(void) = 0;
        bool                isEnoughToSign(Bureaucrat &b);
        bool                isEnoughToExec(Bureaucrat &b);

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
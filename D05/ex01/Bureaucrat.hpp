#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

#define MIN_GRADE 150
#define MAX_GRADE 1

 class Bureaucrat {

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
         * Constructor/Destructor
         */
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat &ref);
        ~Bureaucrat(void);

        /**
         * Overload
         */
        void			operator+=(int const value);
        void			operator-=(int const value);

        /**
         * Getters
         */
        int                    getGrade(void) const;
        std::string            getName(void) const;

        /**
        * Method
        */
        void                    increment(int const value);
        void                    decrement(int const value);
        void                    signForm(Form &ref);

        private:

            /**
             * Property
             */
            std::string const   name;
            int                 grade;
            // Avoid default constructor
            Bureaucrat(void);
        
 };

std::ostream &operator<<(std::ostream &stream, Bureaucrat &ref);

#endif
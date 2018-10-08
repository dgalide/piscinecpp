#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

#include <iostream>

#define MIN_GRADE 150
#define MAX_GRADE 1

 class Bureaucrat {

    class GradeTooLowException : public std::exception {

        public:
            GradeTooLowException(void);
            GradeTooLowException(const GradeTooLowException &ref);

            virtual ~GradeTooLowException(void) throw();

            virtual const char    *what() const throw();

    };

    class GradeTooHighException : public std::exception {

        public:
            GradeTooHighException(void);
            GradeTooHighException(const GradeTooHighException &ref);

            virtual ~GradeTooHighException(void) throw();

            virtual const char    *what() const throw();
    };

     public:

        /**
         * Constructor/Destructor
         */
        Bureaucrat(std::string name);
        Bureaucrat(Bureaucrat &ref);
        ~Bureaucrat(void);

        /**
         * Property
         */
        std::string const   name;
        int                 grade;

        /**
         * Getters
         */
        int                    getGrade(void) const;
        std::string            getName(void) const;

        /**
         * Method
         */
        void                    increment(void);
        void                    decrement(void);

    private:

        Bureaucrat(void);
        
 };

std::ostream &operator<<(std::ostream &stream, Bureaucrat &ref);

#endif
#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

#include <iostream>

#define MIN_GRADE 150
#define MAX_GRADE 1

 class Bureaucrat {

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
         * Constructor/Destructor
         */
        Bureaucrat(std::string name);
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

        private:

            /**
             * Method
             */
            void                    increment(int const value);
            void                    decrement(int const value);

            /**
             * Property
             */
            std::string const   name;
            int                 grade;

    private:

        // Avoid default constructor
        Bureaucrat(void);
        
 };

std::ostream &operator<<(std::ostream &stream, Bureaucrat &ref);

#endif
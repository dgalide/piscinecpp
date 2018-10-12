#ifndef SPAN_HPP
 #define SPAN_HPP

#include <iostream>
#include <vector>

class Span {

    public:

        class ArrayFull: public std::exception {
            public:
                ArrayFull(void);
                ArrayFull(ArrayFull const &ref);
                ArrayFull &operator=(ArrayFull const &e);
                virtual ~ArrayFull(void) throw();
                virtual const char* what() const throw();
                
        };

        class ArrayEmpty: public std::exception {
            public:
                ArrayEmpty(void);
                ArrayEmpty(ArrayEmpty const &ref);
                ArrayEmpty &operator=(ArrayEmpty const &e);
                virtual ~ArrayEmpty(void) throw();
                virtual const char* what() const throw();
                
        };

        class NotEnoughData: public std::exception {
            public:
                NotEnoughData(void);
                NotEnoughData(NotEnoughData const &ref);
                NotEnoughData &operator=(NotEnoughData const &e);
                virtual ~NotEnoughData(void) throw();
                virtual const char* what() const throw();
                
        };

        /**
         * Constructor / Destructor
         */
        Span(unsigned int n);
        Span(Span const &ref);
        ~Span(void);

        /**
         * Assignation Operator
         */
        Span    &operator=(Span const &ref);

        /**
         * Method
         */
        void    addNumber(int a);
        int     shortestSpan(void);
        int     longestSpan(void);
        int     getSpan(int a, int b);

        /**
         * Getters
         */
        unsigned int     getN(void) const;

    private:
        /**
         * Property
         */
        std::vector<int>    *v;
        unsigned int        n;

        // Avoid Default
        Span(void);

    private:

};

#endif
#ifndef PEON_HPP
 #define PEON_HPP

#include <iostream>
#include <sstream>

#include "Victim.hpp"

class Peon: public Victim {

    public:

        /**
         * Constructors/Destructor/
         */
        Peon(std::string name);
        Peon(Peon const &ref);
        ~Peon(void);

        /**
         * Overloads
         */
        Peon    &operator=(Peon const &ref);

        void virtual            getPolymorphed(void) const;

    private:

        // Avoid default constructor -> =delete is C++11 extension :(
        Peon(void);
};

/**
 * << operator being defined here 
 */
std::ostream    &operator<<(std::ostream &out, Peon const &ref);

#endif
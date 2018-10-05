#ifndef SORCERER_HPP
 #define SORCERER_HPP

#include <iostream>
#include <sstream>
#include "Victim.hpp"

class Sorcerer {

    public:

        /**
         * Constructors/Destructor/
         */
        Sorcerer(std::string name, std::string title);
        Sorcerer(Sorcerer const &ref);
        ~Sorcerer(void);

        /**
         * Overloads
         */
        Sorcerer    &operator=(Sorcerer const &ref);

        /**
         * Getters
         */
        std::string      getName(void) const;
        std::string      getTitle(void) const;

        /**
         * Setters
         */
        void            setName(std::string name);
        void            setTitle(std::string title);

        /**
         * Methods
         */
        std::string     introduceString(void) const;
        void            introduceYourself(void) const;
        void            polymorph(Victim const &v) const;

    private:

        // Avoid default constructor -> =delete is C++11 extension :(
        Sorcerer(void);

        std::string name;
        std::string title;
};

/**
 * << operator being defined here 
 */
std::ostream    &operator<<(std::ostream &out, Sorcerer const &ref);

#endif
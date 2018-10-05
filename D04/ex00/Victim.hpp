#ifndef VICTIM_HPP
 #define VICTIM_HPP

#include <iostream>
#include <sstream>

class Victim {

    public:

        /**
         * Constructors/Destructor/
         */
        Victim(std::string name);
        Victim(Victim const &ref);
        ~Victim(void);

        /**
         * Overloads
         */
        Victim    &operator=(Victim const &ref);

        /**
         * Getters
         */
        std::string      getName(void) const;

        /**
         * Setters
         */
        void            setName(std::string name);

        /**
         * Methods
         */
        std::string     introduceString(void) const;
        void            introduceYourself(void) const;
        void virtual            getPolymorphed(void) const;

    private:

        // Avoid default constructor -> =delete is C++11 extension :(
        Victim(void);

        std::string name;
        std::string title;
};

/**
 * << operator being defined here 
 */
std::ostream    &operator<<(std::ostream &out, Victim const &ref);

#endif
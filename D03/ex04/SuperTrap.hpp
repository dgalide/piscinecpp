#ifndef SUPERTRAP_HPP
 #define SUPERTRAP_HPP

 #include <iostream>
 #include "ClapTrap.hpp"
 #include "ScavTrap.hpp"
 #include "FragTrap.hpp"
 #include "NinjaTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap {

     public:
        SuperTrap(std::string name);
        ~SuperTrap(void);

        SuperTrap(SuperTrap const &ref);
        SuperTrap &operator=(SuperTrap const &ref);

        void            rangedAttack(std::string const & target);
        void            meleeAttack(std::string const & target);
 };

#endif
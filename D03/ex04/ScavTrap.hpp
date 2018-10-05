#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

 #include <iostream>
 #include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

     public:
        ScavTrap(std::string name);
        ~ScavTrap(void); 

        ScavTrap(ScavTrap const &ref);
        ScavTrap &operator=(ScavTrap const &ref);

        void            rangedAttack(std::string const & target);
        void            meleeAttack(std::string const & target);

        void            challengeNewcomer(void);

 };

#endif
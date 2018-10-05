#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

 #include <iostream>
 #include "ClapTrap.hpp"

class ScavTrap: ClapTrap {

     public:
        ScavTrap(std::string name);
        ~ScavTrap(void); 

        ScavTrap(ScavTrap const &ref);
        ScavTrap &operator=(ScavTrap const &ref);

        void        challengeNewcomer(void);

 };

#endif
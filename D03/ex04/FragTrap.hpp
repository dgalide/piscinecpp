#ifndef FRAGTRAP_HPP
 #define FRAGTRAP_HPP

 #include <iostream>
 #include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {

     public:
        FragTrap(std::string name);
        ~FragTrap(void); 

        FragTrap(FragTrap const &ref);
        FragTrap &operator=(FragTrap const &ref);

        void            rangedAttack(std::string const & target);
        void            meleeAttack(std::string const & target);

        void            vaulthunter_dot_exe(std::string const & target);

 };

#endif
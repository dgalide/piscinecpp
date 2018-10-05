#ifndef NINJATRAP_HPP
 #define NINJATRAP_HPP

 #include <iostream>
 #include "ClapTrap.hpp"
 #include "ScavTrap.hpp"
 #include "FragTrap.hpp"

class NinjaTrap: virtual public ClapTrap {

     public:
        NinjaTrap(std::string name);
        ~NinjaTrap(void); 

        NinjaTrap(NinjaTrap const &ref);
        NinjaTrap &operator=(NinjaTrap const &ref);

        void            rangedAttack(std::string const & target);
        void            meleeAttack(std::string const & target);

        void            ninjaShoebox(void);
        void            ninjaShoebox(ScavTrap &scav);
        void            ninjaShoebox(FragTrap &frag);
        void            ninjaShoebox(NinjaTrap &ninja);
        void            ninjaShoebox(ClapTrap &clap);


 };

#endif
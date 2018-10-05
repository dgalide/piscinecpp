#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"

int main(void) {

    FragTrap ft("W1");
    ScavTrap st("W2");
    NinjaTrap nt("W3");
    SuperTrap spt("W5");

    ft.vaulthunter_dot_exe("Another Warrior");
    st.challengeNewcomer();
    nt.ninjaShoebox();
    nt.ninjaShoebox(ft);
    nt.ninjaShoebox(st);
    nt.ninjaShoebox(nt);
    spt.meleeAttack("SuperTrapMelee");
    spt.rangedAttack("SuperTrapRanged");
    return 0;
}
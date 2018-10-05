#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {

    FragTrap ft("W1");
    ScavTrap st("W2");
    NinjaTrap nt("W3");
    ClapTrap ct("W4");

    ft.vaulthunter_dot_exe("Another Warrior");
    st.challengeNewcomer();
    nt.ninjaShoebox();
    nt.ninjaShoebox(ft);
    nt.ninjaShoebox(st);
    nt.ninjaShoebox(nt);
    nt.ninjaShoebox(ct);
    ct.meleeAttack("Tango");
    return 0;
}
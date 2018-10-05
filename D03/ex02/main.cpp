#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

    FragTrap ft("W1");
    ScavTrap st("W2");

    ft.vaulthunter_dot_exe("Another Warrior");
    st.challengeNewcomer();
    return 0;
}
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void) {
	
		Weapon        c = Weapon("crude spiked club");
		HumanA bob("Bob", c);
		bob.attack();
		c.setType("some other type of club");
		bob.attack();
	
	
		Weapon        club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		return 0;
}
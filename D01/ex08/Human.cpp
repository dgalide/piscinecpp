#include "Human.hpp"

void Human::meleeAttack(std::string const &target) {
	std::cout << "Melee Attack" << std::endl;
}

void Human::rangedAttack(std::string const &target) {
	std::cout << "Ranged Attack" << std::endl;
}

void Human::intimidatingShout(std::string const &target) {
	std::cout << "Intimidation Attack" << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {

	  void (Human::*fns[3])(std::string const & target) = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };
	  std::string funcName[3] = {"melee", "ranged", "intimidatingShout"};

	  for (int i = 0; i < 3;i++) {
	  	if (funcName[i] == action_name) {
	  		(this->*fns[i])(target);
	  	}
	  }
}
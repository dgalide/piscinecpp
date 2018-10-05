#include "NinjaTrap.hpp"

/**
 * Constructor
 */
NinjaTrap::NinjaTrap(std::string name): ClapTrap(name) {
    std::cout << name << " the NinjaTrapper has born." << " Handsome Jack !" << std::endl;
    this->setHitPoint(60);
    this->setMaxHitPoint(60);
    this->setEnergyPoint(120);
    this->setMaxEnergyPoint(120);
    this->setLevel(1);
    this->setMeleeAttackDamage(60);
    this->setRangedAttackDamage(5);
    this->setArmorDamageReduction(0);
}

/**
 * Copy Constructor
 */
NinjaTrap::NinjaTrap(NinjaTrap const &ref): ClapTrap(ref) {
    std::cout << ref.getName() << " the NinjaTrapper has been constructor copied." << " Handsome Jack !" << std::endl;
    this->setHitPoint(ref.getHitPoint());
    this->setMaxHitPoint(ref.getMaxHitPoint());
    this->setEnergyPoint(ref.getEnergyPoint());
    this->setMaxEnergyPoint(ref.getMaxEnergyPoint());
    this->setLevel(ref.getLevel());
    this->setMeleeAttackDamage(ref.getMeleeAttackDamage());
    this->setRangedAttackDamage(ref.getRangedAttackDamage());
    this->setArmorDamageReduction(ref.getArmorDamageReduction());
    this->setName(ref.getName());
    *this = ref;
}

/**
 * Assignation overload
 */
NinjaTrap &NinjaTrap::operator=(NinjaTrap const &ref) {
    std::cout << ref.getName() << " the NinjaTrapper has been operator copied." << " Handsome Jack !" << std::endl;
    if (this != &ref) {
        this->setHitPoint(ref.getHitPoint());
        this->setMaxHitPoint(ref.getMaxHitPoint());
        this->setEnergyPoint(ref.getEnergyPoint());
        this->setMaxEnergyPoint(ref.getMaxEnergyPoint());
        this->setLevel(ref.getLevel());
        this->setMeleeAttackDamage(ref.getMeleeAttackDamage());
        this->setRangedAttackDamage(ref.getRangedAttackDamage());
        this->setArmorDamageReduction(ref.getArmorDamageReduction());
        this->setName(ref.getName());
    }
    return *this;
}

/**
 * Destructor
 */
NinjaTrap::~NinjaTrap(void) {
    std::cout << this->getName() << " the NinjaTrapper died." << std::endl;
}

/**
 *  Method
*/

void NinjaTrap::meleeAttack(std::string const & target) {
    std::cout << this->getName() << " the NinjaTrapper Attacks " << target << " at melee, causing " << this->getRangedAttackDamage() << " damage !" << std::endl;
}

void NinjaTrap::rangedAttack(std::string const & target) {
    std::cout << this->getName() << " the NinjaTrapper Attacks " << target << " at range, causing " << this->getRangedAttackDamage() << " damage !" << std::endl; 
}


void            NinjaTrap::ninjaShoebox(void) {
    std::cout << "Are you trying to attack someone ? This isn't the good way bruh..." << std::endl;
}

void            NinjaTrap::ninjaShoebox(ScavTrap &scav) {
    std::cout << "Ninja Attacking scavTrapper " << scav.getName() << std::endl;
}

void            NinjaTrap::ninjaShoebox(FragTrap &frag) {
    std::cout << "Ninja Attacking fragTrapper " << frag.getName() << std::endl;
}

void            NinjaTrap::ninjaShoebox(NinjaTrap &ninja) {
    std::cout << "Ninja Attacking ninjaTrapper " << ninja.getName() << std::endl;
}

void            NinjaTrap::ninjaShoebox(ClapTrap &clap) {
    std::cout << "Ninja Attacking clapTrapper" << clap.getName() << std::endl;
}
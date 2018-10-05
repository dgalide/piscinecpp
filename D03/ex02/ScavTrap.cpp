#include "ScavTrap.hpp"

/**
 * Constructor
 */
ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    std::cout << name << " the ScavTrapper has born." << " Handsome Jack !" << std::endl;
    this->setHitPoint(100);
    this->setMaxHitPoint(100);
    this->setEnergyPoint(50);
    this->setMaxEnergyPoint(50);
    this->setLevel(1);
    this->setMeleeAttackDamage(30);
    this->setRangedAttackDamage(15);
    this->setArmorDamageReduction(3);
}

/**
 * Copy Constructor
 */
ScavTrap::ScavTrap(ScavTrap const &ref): ClapTrap(ref) {
    std::cout << ref.getName() << " the ScavTrapper has been constructor copied." << " Handsome Jack !" << std::endl;
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
ScavTrap &ScavTrap::operator=(ScavTrap const &ref) {
    std::cout << ref.getName() << " the ScavTrapper has been operator copied." << " Handsome Jack !" << std::endl;
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
ScavTrap::~ScavTrap(void) {
    std::cout << this->getName() << " the ScavTrapper died." << std::endl;
}

/**
 *  Method
*/

void        ScavTrap::challengeNewcomer(void) {
    
        std::string challenges[] = {"A Useless Random Challenge, Which Does nothing except prompting a useless message.",
                                "You prefer ... ? Or you prefer ... ?",
                                "Shifumi !",
                                };
        srand(time(0));
        int index = rand() % 3;
        std::cout << "Random Challenge lunch by " << this->getName() << " the ScavTrapper -> " << challenges[index] << std::endl;
        this->setEnergyPoint(this->getEnergyPoint() - 25);
    
}
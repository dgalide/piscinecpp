#include "FragTrap.hpp"

/**
 * Constructor
 */
FragTrap::FragTrap(std::string name): ClapTrap(name) {
    std::cout << name << " the FragTrapper has born." << " Handsome Jack !" << std::endl;
    this->setHitPoint(100);
    this->setMaxHitPoint(100);
    this->setEnergyPoint(100);
    this->setMaxEnergyPoint(100);
    this->setLevel(1);
    this->setMeleeAttackDamage(30);
    this->setRangedAttackDamage(20);
    this->setArmorDamageReduction(5);
}

/**
 * Copy Constructor
 */
FragTrap::FragTrap(FragTrap const &ref): ClapTrap(ref) {
    std::cout << ref.getName() << " the FragTrapper has been constructor copied." << " Handsome Jack !" << std::endl;
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
FragTrap &FragTrap::operator=(FragTrap const &ref) {
    std::cout << ref.getName() << " the FragTrapper has been operator copied." << " Handsome Jack !" << std::endl;
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
FragTrap::~FragTrap(void) {
    std::cout << this->getName() << " the FragTrapper died." << std::endl;
}

/**
 *  Method
*/

void FragTrap::meleeAttack(std::string const & target) {
    std::cout << this->getName() << " the FragTrapper Attacks " << target << " at melee, causing " << this->getRangedAttackDamage() << " damage !" << std::endl;
}

void FragTrap::rangedAttack(std::string const & target) {
    std::cout << this->getName() << " the FragTrapper Attacks " << target << " at range, causing " << this->getRangedAttackDamage() << " damage !" << std::endl; 
}

void        FragTrap::vaulthunter_dot_exe(std::string const &target) {
    if (this->getEnergyPoint() < 25) {
        std::cout << this->getName() << " the FragTrapper does not have enough energy point :(" << std::endl;
    } else {
        std::string attacks[] = {"A Useless Random Attack, Which Does nothing except prompting a useless message.",
                                "Freeze Attack, nobody moves!",
                                "Deflagration, nothing left on the battlefield.",
                                "Giant Mass in Action !",
                                "Energy Restoration............. Just Kidding, Fuck off and die !"
                                };
        srand(time(0));
        int index = rand() % 5;
        std::cout << "Random Attack lunch by " << this->getName() << " Attack " << target << " with -> " << attacks[index] << std::endl;
        this->setEnergyPoint(this->getEnergyPoint() - 25);
    }
}
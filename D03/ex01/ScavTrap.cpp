#include "ScavTrap.hpp"

/**
 * Constructor
 */
ScavTrap::ScavTrap(std::string name): name(name) {
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
ScavTrap::ScavTrap(ScavTrap const &ref) {
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

void ScavTrap::meleeAttack(std::string const & target) {
    std::cout << this->getName() << " the ScavTrapper Attacks " << target << " at melee, causing " << this->getRangedAttackDamage() << " damage !" << std::endl;
}

void ScavTrap::rangedAttack(std::string const & target) {
    std::cout << this->getName() << " the ScavTrapper Attacks " << target << " at range, causing " << this->getRangedAttackDamage() << " damage !" << std::endl; 
}

void        ScavTrap::takeDamage(unsigned int amount) {
    std::cout << this->getName() << " the ScavTrapper beeing attacked ! Causing the pert of " << amount << " hitpoints." << std::endl;
    
    if ((this->getHitPoint() - (int)(amount - this->getArmorDamageReduction())) < 0) {
        this->setHitPoint(0);
    } else {
        this->setHitPoint(this->getHitPoint() - (amount - this->getArmorDamageReduction()));
    }
}

void        ScavTrap::beRepaired(unsigned int amount) {
    std::cout << this->getName() << " the ScavTrapper beeing repaired ! Causing the gain of " << amount << " hitpoints." << std::endl;

    if ((int)(this->getHitPoint() + amount) > this->getMaxHitPoint()) {
        this->setHitPoint(this->getMaxHitPoint());
    } else {
        this->setHitPoint(this->getHitPoint() + amount);
    }
}

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

/**
 * Getters
 */

int         ScavTrap::getHitPoint(void) const {
    return this->hitPoint;
}

int         ScavTrap::getMaxHitPoint(void) const {
    return this->maxHitPoint;
}

int         ScavTrap::getEnergyPoint(void) const {
    return this->energyPoint;
}

int         ScavTrap::getMaxEnergyPoint(void) const {
    return this->maxEnergyPoint;
}

int         ScavTrap::getLevel(void) const {
    return this->level;
}

int         ScavTrap::getMeleeAttackDamage(void) const {
    return  this->meleeAttackDamage;
}

int         ScavTrap::getRangedAttackDamage(void) const {
    return  this->rangedAttackDamage;
}

int         ScavTrap::getArmorDamageReduction(void) const {
    return this->armorDamageReduction;
}

std::string ScavTrap::getName(void) const {
    return this->name;
}

/**
 * Setters
 */

void        ScavTrap::setHitPoint(int hitPoint) {
    this->hitPoint = hitPoint;
}

void        ScavTrap::setMaxHitPoint(int hitPoint) {
    this->maxHitPoint = hitPoint;
}

void        ScavTrap::setEnergyPoint(int energyPoint) {
    this->energyPoint = energyPoint;
}

void        ScavTrap::setMaxEnergyPoint(int energyPoint) {
    this->maxEnergyPoint = energyPoint;
}

void        ScavTrap::setLevel(int level) {
    this->level = level;
}

void        ScavTrap::setMeleeAttackDamage(int damage) {
    this->meleeAttackDamage = damage;
}

void        ScavTrap::setRangedAttackDamage(int damage) {
    this->rangedAttackDamage = damage;
}

void        ScavTrap::setArmorDamageReduction(int reduction) {
    this->armorDamageReduction = reduction;
}

void        ScavTrap::setName(std::string name) {
    this->name = name;
}
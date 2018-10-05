#include "ClapTrap.hpp"

/**
 * Constructor
 */
ClapTrap::ClapTrap(std::string name): name(name) {
    std::cout << name << " the inherited ClapTrapper has born." << " Handsome Jack !" << std::endl;
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
ClapTrap::ClapTrap(ClapTrap const &ref) {
    std::cout << ref.getName() << " the inherited ClapTrapper has been constructor copied." << " Handsome Jack !" << std::endl;
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
ClapTrap &ClapTrap::operator=(ClapTrap const &ref) {
    std::cout << ref.getName() << " the inherited ClapTrapper has been operator copied." << " Handsome Jack !" << std::endl;
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
ClapTrap::~ClapTrap(void) {
    std::cout << this->getName() << " the inherited ClapTrapper died." << std::endl;
}

/**
 *  Method
*/

void        ClapTrap::takeDamage(unsigned int amount) {
    std::cout << this->getName() << " the inherited ClapTrapper beeing attacked ! Causing the pert of " << amount << " hitpoints." << std::endl;
    
    if ((this->getHitPoint() - (int)(amount - this->getArmorDamageReduction())) < 0) {
        this->setHitPoint(0);
    } else {
        this->setHitPoint(this->getHitPoint() - (amount - this->getArmorDamageReduction()));
    }
}

void        ClapTrap::beRepaired(unsigned int amount) {
    std::cout << this->getName() << " the inherited ClapTrapper beeing repaired ! Causing the gain of " << amount << " hitpoints." << std::endl;

    if ((int)(this->getHitPoint() + amount) > this->getMaxHitPoint()) {
        this->setHitPoint(this->getMaxHitPoint());
    } else {
        this->setHitPoint(this->getHitPoint() + amount);
    }
}

/**
 * Getters
 */

int         ClapTrap::getHitPoint(void) const {
    return this->hitPoint;
}

int         ClapTrap::getMaxHitPoint(void) const {
    return this->maxHitPoint;
}

int         ClapTrap::getEnergyPoint(void) const {
    return this->energyPoint;
}

int         ClapTrap::getMaxEnergyPoint(void) const {
    return this->maxEnergyPoint;
}

int         ClapTrap::getLevel(void) const {
    return this->level;
}

int         ClapTrap::getMeleeAttackDamage(void) const {
    return  this->meleeAttackDamage;
}

int         ClapTrap::getRangedAttackDamage(void) const {
    return  this->rangedAttackDamage;
}

int         ClapTrap::getArmorDamageReduction(void) const {
    return this->armorDamageReduction;
}

std::string ClapTrap::getName(void) const {
    return this->name;
}

/**
 * Setters
 */

void        ClapTrap::setHitPoint(int hitPoint) {
    this->hitPoint = hitPoint;
}

void        ClapTrap::setMaxHitPoint(int hitPoint) {
    this->maxHitPoint = hitPoint;
}

void        ClapTrap::setEnergyPoint(int energyPoint) {
    this->energyPoint = energyPoint;
}

void        ClapTrap::setMaxEnergyPoint(int energyPoint) {
    this->maxEnergyPoint = energyPoint;
}

void        ClapTrap::setLevel(int level) {
    this->level = level;
}

void        ClapTrap::setMeleeAttackDamage(int damage) {
    this->meleeAttackDamage = damage;
}

void        ClapTrap::setRangedAttackDamage(int damage) {
    this->rangedAttackDamage = damage;
}

void        ClapTrap::setArmorDamageReduction(int reduction) {
    this->armorDamageReduction = reduction;
}

void        ClapTrap::setName(std::string name) {
    this->name = name;
}
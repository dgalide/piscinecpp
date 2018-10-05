#include "SuperTrap.hpp"

/**
 * Constructor
 */
SuperTrap::SuperTrap(std::string name): ClapTrap(name), NinjaTrap(name), FragTrap(name) {
    std::cout << name << " the SuperTrapper has born." << " Handsome Jack !" << std::endl;
    this->setHitPoint(100);
    this->setMaxHitPoint(100);
    this->setEnergyPoint(120);
    this->setMaxEnergyPoint(120);
    this->setLevel(1);
    this->setMeleeAttackDamage(60);
    this->setRangedAttackDamage(20);
    this->setArmorDamageReduction(5);
}

/**
 * Copy Constructor
 */
SuperTrap::SuperTrap(SuperTrap const &ref): ClapTrap(ref), NinjaTrap(ref), FragTrap(ref) {
    std::cout << ref.getName() << " the SuperTrapper has been constructor copied." << " Handsome Jack !" << std::endl;
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
SuperTrap &SuperTrap::operator=(SuperTrap const &ref) {
    std::cout << ref.getName() << " the SuperTrapper has been operator copied." << " Handsome Jack !" << std::endl;
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
SuperTrap::~SuperTrap(void) {
    std::cout << this->getName() << " the SuperTrapper died." << std::endl;
}

/**
 * Method
 */

void SuperTrap::meleeAttack(std::string const & target) {
    NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(std::string const & target) {
    FragTrap::rangedAttack(target);
}
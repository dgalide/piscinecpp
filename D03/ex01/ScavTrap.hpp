#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

 #include <iostream>

class ScavTrap {

     public:
        ScavTrap(std::string name);
        ~ScavTrap(void); 

        ScavTrap(ScavTrap const &ref);
        ScavTrap &operator=(ScavTrap const &ref);

        /**    Method   */
        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        void        challengeNewcomer(void);

        /** Getters */
        int         getHitPoint(void) const;
        int         getMaxHitPoint(void) const;
        int         getEnergyPoint(void) const;
        int         getMaxEnergyPoint(void) const;
        int         getLevel(void) const;
        int         getMeleeAttackDamage(void) const;
        int         getRangedAttackDamage(void) const;
        int         getArmorDamageReduction(void) const;
        std::string getName(void) const;

        /** Setters */
        void        setHitPoint(int);
        void        setMaxHitPoint(int);
        void        setEnergyPoint(int);
        void        setMaxEnergyPoint(int);
        void        setLevel(int);
        void        setMeleeAttackDamage(int);
        void        setRangedAttackDamage(int);
        void        setArmorDamageReduction(int);
        void        setName(std::string);

     private:

        /** Attributes */
        int             hitPoint;
        int             maxHitPoint;
        int             energyPoint;
        int             maxEnergyPoint;
        int             level;
        std::string     name;
        int             meleeAttackDamage;
        int             rangedAttackDamage;
        int             armorDamageReduction;

 };

#endif
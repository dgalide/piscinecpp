#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

 #include <iostream>

class ClapTrap {

     public:
        ClapTrap(std::string name);
        ~ClapTrap(void); 

        ClapTrap(ClapTrap const &ref);
        ClapTrap &operator=(ClapTrap const &ref);

        /**    Method   */
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

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

     protected:

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
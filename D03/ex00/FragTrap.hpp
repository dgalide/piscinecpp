#ifndef FRAGTRAP_HPP
 #define FRAGTRAP_HPP

 #include <iostream>

 class FragTrap {

     public:
        FragTrap(std::string name);
        ~FragTrap(void);

        FragTrap(FragTrap const &ref);
        FragTrap &operator=(const FragTrap &ref);

        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

        int         getHitPoint(void);
        int         getMaxHitPoint(void);
        int         getEnergyPoint(void);
        int         getMaxEnergyPoint(void);
        int         getLevel(void);
        int         getMeleeAttackDamage(void);
        int         getRangedAttackDamage(void);
        int         getArmorDamageReduction(void);
        std::string getName(void);

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
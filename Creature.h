//
//  Creature.h
//
//  Created by Matt on 5/15/21.
//  Copyright © 2021 Matt. All rights reserved.
//

#ifndef Creature_h
#define Creature_h
#include <string>
class Creature
{
protected:
    std::string name;
    char symbol;
    int health;
    int damage;
    int gold;
public:
    //default constructor
    Creature()
    
    {
        name = "";
        symbol = ' ';
        health = 0;
        damage = 0;
        gold = 0;
        
    }
    //2nd constructor
    Creature(std::string Name, char Symbol, int Health, int Damage, int Gold)
    {
        name = Name;
        symbol = Symbol;
        health = Health;
        damage = Damage;
        gold = Gold;
    }
    std::string getName() const
    {
        return name;
    }
    
    char getSymbol() const
    {
        return symbol;
    }
    
    int getHealth() const
    {
        return health;
    }
    
    int getDamage() const
    {
        return damage;
    }
    
    int getGold() const
    {
        return gold;
    }
    
    void reduceHealth(int Health)
    {
        health -= Health;
    }
    
    void restoreHealth(int Health)
    {
        health += Health;
    }
    
    void addGold(int Gold)
    {
        gold+= Gold;
    }
    
    bool isDead()
    {
       
        return health <= 0;
    }
};

#endif /* Creature_h */

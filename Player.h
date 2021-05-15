//
//  Player.h
//
//  Created by Matt on 5/15/21.
//  Copyright © 2021 Matt. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include <string>
#include "Creature.h"



class Player : public Creature
{
private:
    int level = 1;
public:
    //constructor
    Player(std::string Name, char Symbol, int Health, int Damage, int Gold, int Level)
    : Creature(Name, '@', 10, 1, 0)
    {
    }
    void levelUp()
    {
        ++level;
        ++damage;
       
    }
    int getLevel() const
    {
        return level;
    }
    bool hasWon()
    {
        
        return level >= 20;
    }
};

#endif /* Player_h */

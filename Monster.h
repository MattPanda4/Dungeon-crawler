//
//  Monster.h
//
//  Created by Matt on 5/15/21.
//  Copyright © 2021 Matt. All rights reserved.
//

#ifndef Monster_h
#define Monster_h
#include "Player.h"
#include "Creature.h"
#include <string>
#include <array>


int getRandomNumber(int min, int max)
{
    static constexpr double fraction {1.0/(RAND_MAX + 1.0)};
        
    return min + static_cast<int>((max-min+1) * (rand() * fraction));
        
 };

class Monster : public Creature
{
public:
    enum Type
    {
        DRAGON, ORC, SLIME, max_types
    };
private:
    static const Creature getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<size_t>(Type::max_types)> monsterData{
        {
            {"Dragon", 'D', 20 , 4, 100},
            {"Orc" , 'O' , 4, 2, 25},
            {"Slime" , 'S' , 1 , 1, 10} }
        };
            return monsterData.at(static_cast<size_t>(type));
            
    }
public: Monster(Type type) : Creature{getDefaultCreature(type)}
    {
        
    }
    static const Monster getRandomMonster()
    {
       
        int num{getRandomNumber(0, static_cast<int>(Type::max_types)-1)};
        return Monster{static_cast<Type>(num)};
        
    }
};


void AttackMonster(Player &player, Monster &monster)
{
    if(player.isDead())
    {
        return;
    }
    
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage!\n";
    monster.reduceHealth(player.getDamage());
    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << " and won the battle!\n";
        player.levelUp();
        std::cout << "You are now level: " << player.getLevel() << ". You found: " << monster.getGold() << " gold.";
        player.addGold(monster.getGold());
        player.restoreHealth(monster.getDamage());
        std::cout << " You have " << player.getHealth() << " health left!\n";
        std::cout << std::endl;
        return;
    }
}
    
void AttackPlayer(Monster &monster, Player &player)
    {
        if(monster.isDead())
        {
            return;
        }
        
        
        
        std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage!\n";
        player.reduceHealth(monster.getDamage());
        if (player.isDead())
        {
            std::cout << "You were killed by the " << monster.getName() << " and lost the battle.\n";
            std::cout << "Game over!\n";
        }
    }
    
    


void fightMonster(Player &player)
{
    char answer = '\0';
    Monster monster{Monster::getRandomMonster()};
    std::cout << "You have encountered a(n) " << monster.getName() << std::endl;
    while(!monster.isDead() && !player.isDead()){
        std::cout << "(R)un or (Fight): ";
        std::cin.ignore();
        std::cin >> answer;
    if ( answer == 'r' || answer == 'R' )
    {
        std::cout << "You chose to run away.\n";
    }
    else if (answer == 'f' || answer == 'F')
    {
        std::cout << "You have chosen to fight.\n";
        AttackMonster(player, monster);
        AttackPlayer(monster, player);
    }
    if (answer == 'r' || answer == 'R')
    {
        {
            if (getRandomNumber(1, 2) == 1)
            {
                std::cout << "You have escaped successfully!\n";
                return;
                
            }
            else
            {
                std::cout << "You did not escape, try again or fight.\n";
                AttackPlayer(monster, player);
                continue;
            }
        }
        
    }
      
    
    }
}

#endif /* Monster_h */

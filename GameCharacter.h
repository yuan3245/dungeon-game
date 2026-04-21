#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
public:
    GameCharacter();
    GameCharacter(string,string,int,int,int,int);
    virtual void triggerEvent();
    int takeDamage(int);

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setMoney(int);
    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getMoney();

//private:
    string name;
    int maxHealth;
    int currentHealth;
    int attack;
    int money;

};



#endif // GAMECHARACTER_H_INCLUDED

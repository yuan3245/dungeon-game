#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Item : public Object{
public:
    Item();
    Item(string, int, int, int);

    void setHealth(int);
    void setAttack(int);
    void setMoney(int);

    int getHealth();
    int getAttack();
    int getMoney();


//private:
    int health;
    int attack;
    int money;


};



#endif // ITEM_H_INCLUDED

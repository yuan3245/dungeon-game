#include "Item.h"

Item::Item() : Object(){


};

Item::Item(string name, int health, int attack, int money) : Object(name, "Item"){
    this->health=health;
    this->attack=attack;
    this->money=money;

};

void Item::setHealth(int health){
    this->health=health;

};

void Item::setAttack(int attack){
    this->attack=attack;

};

void Item::setMoney(int money){
    this->money=money;

};

int Item::getHealth(){
    return this->health;

};

int Item::getAttack(){
    return this->attack;

};

int Item::getMoney(){
    return this->money;

};

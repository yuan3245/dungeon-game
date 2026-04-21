#include "GameCharacter.h"

GameCharacter::GameCharacter() : Object(){

}

GameCharacter::GameCharacter(string tag, string name, int maxHealth, int currentHealth, int attack, int money) : Object(name, tag){
    this->name=name;
    this->maxHealth=maxHealth;
    this->currentHealth=currentHealth;
    this->attack=attack;
    this->money=money;

}
void GameCharacter::triggerEvent(){

}

int GameCharacter::takeDamage(int damage){
    currentHealth=currentHealth-damage;
    return currentHealth;
}

void GameCharacter::setMaxHealth(int maxhealth){
    this->maxHealth=maxhealth;

}
void GameCharacter::setCurrentHealth(int currenthealth){
    this->currentHealth=currenthealth;

}
void GameCharacter::setAttack(int attack){
    this->attack=attack;

}
void GameCharacter::setMoney(int money){
    this->money=money;

}


int GameCharacter::getMaxHealth(){
    return this->maxHealth;

}
int GameCharacter::getCurrentHealth(){
    return this->currentHealth;

}
int GameCharacter::getAttack(){
    return this->attack;

}
int GameCharacter::getMoney(){
    return this->money;

}



#include "Player.h"

Player::Player(){

}

Player::Player(string name, int maxHealth, int currentHealth, int attack,int money) : GameCharacter("Player", name, 100, currentHealth, attack, money)
{


}

void Player::addItem(Item item){
    inventory.push_back(item);

}

void Player::increaseStates(int currentHealth, int attack, int money){
    int x;
    x=getCurrentHealth();
    x=x+currentHealth;
    setCurrentHealth(x);
    int y;
    y=getAttack();
    y=y+attack;
    setAttack(y);
    int z;
    z=getMoney();
    z=z+money;
    setMoney(z);
}

void Player::changeRoom(Room *room){
    previousRoom=currentRoom;
    currentRoom=room;
}

void Player::triggerEvent(){
    cout<<"Status:"<<endl;
    cout<<"["<<getName()<<"]"<<endl;
    cout<<">Health: "<<getCurrentHealth()<<"/"<<"100"<<endl;
    cout<<">Attack: "<<getAttack()<<endl;
    cout<<">Money: "<<getMoney()<<endl;
}

void Player::setCurrentRoom(Room *currentRoom){
    this->currentRoom=currentRoom;

}


void Player::setPreviousRoom(Room *previousRoom){
    this->previousRoom=previousRoom;

}

void Player::setInventory(vector<Item> inventory){
    this->inventory=inventory;

}

Room* Player::getCurrentRoom(){
    return this->currentRoom;

}

Room* Player::getPreviousRoom(){
    return this->previousRoom;

}

vector<Item> Player::getInventory(){
    return this->inventory;

}




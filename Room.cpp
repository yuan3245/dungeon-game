#include "Room.h"

Room::Room(){

}

Room::Room(int isExit, int index, Object* objects){
    this->isExit=isExit;
    this->index=index;
    this->objects=objects;
}

void Room::setUpRoom(Room* upRoom){
    this->upRoom=upRoom;

}

void Room::setDownRoom(Room* downRoom){
    this->downRoom=downRoom;

}

void Room::setLeftRoom(Room* leftRoom){
    this->leftRoom=leftRoom;

}

void Room::setRightRoom(Room* rightRoom){
    this->rightRoom=rightRoom;

}

void Room::setIsExit(int isExit){
    this->isExit=isExit;

}

void Room::setIndex(int index){
    this->index=index;

}

void Room::setObjects(Object* objects){
    this->objects=objects;

}

Room* Room::getUpRoom(){
    return this->upRoom;

}

Room* Room::getDownRoom(){
    return this->downRoom;

}

Room* Room::getLeftRoom(){
    return this->leftRoom;

}

Room* Room::getRightRoom(){
    return this->rightRoom;

}

int Room::getIsExit(){
    return this->isExit;

}

int Room::getIndex(){
    return this->index;

}

Object* Room::getObjects(){
    return this->objects;
}






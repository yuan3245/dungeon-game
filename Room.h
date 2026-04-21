#ifndef R_OOM_H_INCLUDED
#define R_OOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room
{
public:
    Room();
    Room(int, int, Object*);
    /* Set & Get function*/
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(int);
    void setIndex(int);
    void setObjects(Object*);
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
    int getIsExit();
    int getIndex();
    Object* getObjects();

//private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    int isExit;
    int index;
    Object* objects; /*contain 1 or multiple objects, including monster, npc, etc*/

};


#endif // R_OOM_H_INCLUDED

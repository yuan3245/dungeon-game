#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"

using namespace std;

class NPC: public GameCharacter
{

public:
    NPC();
    NPC(string, string, Item);
    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    void triggerEvent(Player &);

    /* Set & Get function*/
    void setScript(string);
    void setCommodity(Item);
    string getScript();
    Item getCommodity();
//private:
    string script;
    Item commodity;
};


#endif // NPC_H_INCLUDED



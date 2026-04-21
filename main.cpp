#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "GameCharacter.h"
#include "Player.h"
#include "Object.h"
#include "Room.h"
#include "Monster.h"
#include "NPC.h"
#include "Dungeon.h"
using namespace std;

int main(void)
{

  Dungeon dungeon=Dungeon();
  dungeon.runDungeon();

return 0;
}


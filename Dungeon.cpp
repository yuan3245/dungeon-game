#include "Dungeon.h"


Item Medicine=Item("Medicine",20,0,2);
Item WG=Item("Watergun",0,5,0);
Monster Hamster=Monster("Hamster",30,30,5);
NPC Seller=NPC("Seller","Do you want to buy something?",Medicine);
Monster Fireboss("Fireboss",100,100,50);


Dungeon::Dungeon(){

}

void Dungeon::createPlayer(){
    cout<<"Please select game difficulty: "<<endl;
    cout<<"A.easy"<<endl;
    cout<<"B.hard"<<endl;
    char n;
    cin>>n;
    if(n=='a'){ this->player=Player("player",100,100,20,6);  }
    if(n=='b'){ this->player=Player("player",100,100,10,3);  }
}

void Dungeon::createMap(){
    rooms[0]=Room(0, 0, NULL );
    rooms[1]=Room(0, 1, &WG );
    rooms[2]=Room(0, 2, &Hamster);
    rooms[3]=Room(0, 3, &Seller);
    rooms[4]=Room(1, 4, &Fireboss );

    rooms[0].setUpRoom(&rooms[1]);
    rooms[0].setDownRoom(NULL);
    rooms[0].setLeftRoom(NULL);
    rooms[0].setRightRoom(NULL);

    rooms[1].setUpRoom(NULL);
    rooms[1].setDownRoom(&rooms[0]);
    rooms[1].setLeftRoom(NULL);
    rooms[1].setRightRoom(&rooms[2]);

    rooms[2].setUpRoom(&rooms[3]);
    rooms[2].setDownRoom(NULL);
    rooms[2].setLeftRoom(&rooms[1]);
    rooms[2].setRightRoom(NULL);

    rooms[3].setUpRoom(NULL);
    rooms[3].setDownRoom(&rooms[2]);
    rooms[3].setLeftRoom(NULL);
    rooms[3].setRightRoom(&rooms[4]);

    rooms[4].setUpRoom(NULL);
    rooms[4].setDownRoom(NULL);
    rooms[4].setLeftRoom(&rooms[3]);
    rooms[4].setRightRoom(NULL);
}

void Dungeon::startGame(){
    player.setCurrentRoom(&rooms[0]);
}

void Dungeon::chooseAction(){

    if(  (player.currentRoom)->objects==NULL  )
    {
        cout<<"What do you want to do?"<<endl;
        cout<<"A. Move"<<endl;
        cout<<"B. Show Status"<<endl;
        char k;
        cin>>k;
        if(k=='a') { handleMovement();  }
        if(k=='b') { player.triggerEvent();  }
    }
    if(  (player.currentRoom)->objects==&WG  )
    {
        cout<<"What do you want to do?"<<endl;
        cout<<"A. Move"<<endl;
        cout<<"B. Show Status"<<endl;
        cout<<"C. Open the chest"<<endl;
        char k;
        cin>>k;
        if(k=='a') { handleMovement();  }
        if(k=='b') { player.triggerEvent();  }
        if(k=='c')
        {
            player.addItem(WG);
            player.increaseStates(0,5,0);
            cout<<"You pick up the Watergun"<<endl;
           ( (player.currentRoom)->objects)=NULL;
        }
    }
    if(  (player.currentRoom)->objects==&Hamster  )
    {
        cout<<"What do you want to do?"<<endl;
        cout<<"A. Fight with Hamster(atk:5,mhp:30)"<<endl;
        cout<<"B. Show Status"<<endl;
        char k;
        cin>>k;
        if(k=='a')
        {
            Hamster.triggerEvent(player);
            if(Hamster.currentHealth<=0){ cout<<"You get 3 diamonds as reward"<<endl; player.increaseStates(0,0,3);   }
        }
        if(k=='b') { player.triggerEvent();  }
    }
    if(  (player.currentRoom)->objects==&Seller  )
    {
        cout<<"What do you want to do?"<<endl;
        cout<<"A. Move"<<endl;
        cout<<"B. Show Status"<<endl;
        cout<<"C. Talk to Shop"<<endl;
        char k;
        cin>>k;
        if(k=='a') { handleMovement();  }
        if(k=='b') { player.triggerEvent();  }
        if(k=='c') { Seller.triggerEvent(player);  }
    }
    if(  (player.currentRoom)->objects==&Fireboss  )
    {
        if(rooms[1].objects==NULL) { Fireboss.setAttack(25);  }
        cout<<"What do you want to do?"<<endl;
        cout<<"A. Fight with Fireboss(atk:"<<Fireboss.attack<<",mhp:100)"<<endl;
        cout<<"B. Show Status"<<endl;
        char k;
        cin>>k;
        if(k=='a')
        {
            Fireboss.triggerEvent(player);
            if(Fireboss.currentHealth<=0){ cout<<"Congrats, you win the game!"<<endl;  }
        }
        if(k=='b') { player.triggerEvent();  }
    }
}

void Dungeon::handleMovement(){
    char m;
    int a=0,b=0,c=0,d=0;
    cout<<"Where do you want to go?"<<endl;
    if(  (player.currentRoom)->upRoom!=NULL  ) { cout<<"A. Go up"<<endl; a=1; }
    if(  (player.currentRoom)->downRoom!=NULL  ) { cout<<"A. Go down"<<endl; b=1; }
    if(  (player.currentRoom)->leftRoom!=NULL  ) { cout<<"B. Go left"<<endl; c=1; }
    if(  (player.currentRoom)->rightRoom!=NULL  ) { cout<<"B. Go right"<<endl; d=1;  }
    cin>>m;
    if(m=='a')
    {
        if(a==1) {  player.changeRoom( (player.currentRoom)->upRoom );  }
        if(b==1) {  player.changeRoom( (player.currentRoom)->downRoom );  }
    }
    if(m=='b')
    {
        if(c==1) {  player.changeRoom( (player.currentRoom)->leftRoom );  }
        if(d==1) {  player.changeRoom( (player.currentRoom)->rightRoom );  }
    }
    a=0,b=0,c=0,d=0;
}

bool Dungeon::checkGameLogic(){
    if(player.currentHealth<=0||Fireboss.currentHealth<=0)
    {
        return true;
    }
    else{ return false; }
}


void Dungeon::runDungeon(){
    createPlayer();
    createMap();
    startGame();
    bool b=false;
    while(b==false)
    {
        chooseAction();
        b=checkGameLogic();
    }

}



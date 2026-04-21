#include "NPC.h"

NPC::NPC(){

}

NPC::NPC(string name, string script, Item commodity) : GameCharacter("NPC", name, 100, 100, 0,0){
    this->script=script;
    this->commodity=commodity;
}


void NPC::triggerEvent(Player &pl){
    while(1)
    {
        cout<<script<<endl;
        cout<<"A.Medicine(2 diamonds)"<<endl;
        cout<<"B.No, leave"<<endl;
        char j;
        cin>>j;
        if(j=='a')
        {
            if(pl.money>=2)
            {
                cout<<"You get medicine";
                if(pl.currentHealth<=80){ pl.increaseStates(20,0,-2); cout<<"(increase 20 health)"<<endl;  }
                else
                {
                    cout<<"(increase "<<100-pl.currentHealth<<" health)"<<endl;
                    pl.currentHealth=100;
                    pl.increaseStates(0,0,-2);
                }
            }
            else{ cout<<"You don't have enough money!"<<endl;  }
        }
        if(j=='b'){ break; }
    }

}

void NPC::setScript(string script){
    this->script=script;

}

void NPC::setCommodity(Item commodity){
    this->commodity=commodity;

}

string NPC::getScript(){
    return this->script;

}

Item NPC::getCommodity(){
    return this->commodity;

}

#include "Monster.h"

Monster::Monster(){

}

Monster::Monster(string name, int maxHealth, int currentHealth, int attack) : GameCharacter("Monster", name, maxHealth, currentHealth, attack,0){

}

void Monster::triggerEvent(Player &pl){
    int mh=getCurrentHealth();
    int ph=pl.getCurrentHealth();
    int pa=pl.getAttack();
    int ma=getAttack();
    while( 1 )
    {
        cout<<"Choose Action:"<<endl;
        cout<<"A.Attack"<<endl;
        cout<<"B.Retreat"<<endl;
        char m;
        cin>>m;
        if(m=='a')
        {
            cout<<"You choose to attack!"<<endl;

            mh=mh-pa;
            setCurrentHealth(mh);
            cout<<"Your attack does "<<pa<<" damage"<<endl;
            if(mh<=0) { cout<<"You beat "<<getName()<<endl; ((pl.currentRoom)->objects)=NULL; break;  }
            else { cout<<getName()<<" now have "<<mh<<" health"<<endl;  }

            ph=ph-ma;
            pl.setCurrentHealth(ph);
            cout<<getName()<<"'s attack does "<<ma<<" damage"<<endl;
            if(ph<=0) { cout<<"You're dead, game over"<<endl;   break;  }
            else { cout<<"You now have "<<ph<<" health"<<endl;  }
        }
        if(m=='b')
        {
            pl.changeRoom(pl.previousRoom); break;
        }
    }


}


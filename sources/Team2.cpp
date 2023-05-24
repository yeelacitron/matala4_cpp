#include "Team2.hpp"
using namespace std;

namespace ariel{

    Team2::Team2(Character *leader):Team(leader){

    }
    void Team2::print(){
        for (Character * fighter: getFighers())
        {
            cout << fighter->print() << endl;  
        }
    }
    void Team2::attackInOrder(Character* enemy,Team *other){
        for(Character* fighter : getFighers()){
            if(!enemy->isAlive()){
                enemy = replaceEnemy(other);
                if(enemy==NULL){
                    return;
                }
            }
            if(fighter->isAlive()){
                Ninja *nptr = dynamic_cast<Ninja *>(fighter);
                if(nptr==NULL){
                    Cowboy *cowboy = (Cowboy *)(fighter);
                    cowboy->cowboyMove(enemy);
                }
                else{
                    nptr->ninjaMove(enemy);
                }
            }
        }

    }

}
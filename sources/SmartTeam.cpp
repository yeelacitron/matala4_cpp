#include "SmartTeam.hpp"
using namespace std;

namespace ariel{

    SmartTeam::SmartTeam(Character *leader):Team(leader){

    }
    void SmartTeam::attack(Team *other){
        if (other == NULL)
        {
            throw invalid_argument("can't attack null team");
        }
        if(other->stillAlive()==0){
            throw runtime_error("can't attack dead team");
        }
        //check that the team us not dead
        
        Character * enemyToAttack= findEnemy();
        attackInOrder(enemyToAttack, other);
    }
    void SmartTeam::attackInOrder(Character* enemy,Team *other){

    }
    Character* SmartTeam::findEnemy(){
        
        return NULL;
    }
}
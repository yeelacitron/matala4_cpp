#include "Team.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <limits>
#include <vector>

using namespace std;

namespace ariel
{

    Team::Team(Character *leader) : leader(leader)
    {
        this->add(leader);
    }
    Team::~Team()
    {
        for (Character *fighter : fighters)
        {
            delete fighter;
        }
    }

    void Team::add(Character *fighter)
    {
        if (fighters.size() == 10)
        {
            throw runtime_error("The team is full can't add more fighters");
        }
        if (fighter->isInTeam())
        {
            throw runtime_error("The Character is already in a team");
        }
        fighters.emplace_back(fighter);
        fighter->setInTeam(true);
    }
    void Team::attack(Team *other)
    {
        if (other == NULL)
        {
            throw invalid_argument("can't attack null team");
        }
        if(other->stillAlive()==0){
            throw runtime_error("can't attack dead team");
        }
        if (!this->leader->isAlive())
        {
            leader = assaignNewLeader();
            if (leader == NULL)
            {
                throw runtime_error("dead Team can't attack");
            }
        }
        Character *enemyToAttack = replaceEnemy(other);
        if(enemyToAttack==NULL){
            return;
        }

        attackInOrder(enemyToAttack, other);
    }
    void Team::attackInOrder(Character *enemy, Team *other)
    {
        // Itearet over the Cowboys
        for (Character *fighter : fighters)
        {
            if (!enemy->isAlive())
            {
                enemy = replaceEnemy(other);
                if(enemy==NULL){
                    return;
                }
            }
            if(fighter->isAlive()){
                Cowboy *nptr = dynamic_cast<Cowboy *>(fighter);
                if (nptr != NULL)
                {
                    nptr->cowboyMove(enemy);
                }
            }
        }
        // Itearet over the Ninjas
        for (Character *fighter : fighters)
        {
            if (!enemy->isAlive())
            {
                enemy = replaceEnemy(other);
                if(enemy==NULL){
                    return;
                }
            }
            if(fighter->isAlive()){
                Ninja *nptr = dynamic_cast<Ninja *>(fighter);
                if (nptr != NULL)
                {
                    nptr->ninjaMove(enemy);
                }
            }   
        }
    }
    int Team::stillAlive()
    {
        int alives = 0;
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i]->isAlive())
            {
                alives++;
            }
        }
        return alives;
    }
    void Team::print()
    {
        for (Character * fighter: fighters)
        {
            Cowboy *nptr = dynamic_cast<Cowboy *>(fighter);
            if (nptr != NULL)
            {
                cout << fighter->print() << endl;
            }
        }
        for (Character * fighter: fighters)
        {
            Ninja *nptr = dynamic_cast<Ninja *>(fighter);
            if (nptr != NULL)
            {
                cout << fighter->print() << endl;
            }
        }
    }
    Character *Team::getLeader() const
    {
        return leader;
    }

    Character *Team::assaignNewLeader()
    {
        return this->replaceEnemy(this);
    }

    vector<Character *> Team::getFighers()
    {
        return fighters;
    }
    Character *Team::replaceEnemy(Team *enemyTeam)
    {
        Character *enemyToAttack = NULL;
        double distFromEnemy = numeric_limits<double>::max();
        for (Character *enemy : enemyTeam->fighters)
        {
            double curr_dist = leader->distance(enemy);
            if (curr_dist < distFromEnemy && enemy->isAlive())
            {
                distFromEnemy = curr_dist;
                enemyToAttack = enemy;
            }
        }
        return enemyToAttack;
    }

}
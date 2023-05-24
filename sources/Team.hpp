#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Point.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"

namespace ariel{
    class Team{
        private:
            std::vector<Character*> fighters;
            Character * leader;
            
        public:
            Team(Character * leader);
            virtual ~Team();
            void add(Character *fighter);
            void attack(Team *other);
            int stillAlive();
            virtual void print();
            Character* getLeader() const;
            Character* assaignNewLeader();
            virtual void attackInOrder(Character* enemy,Team *other);
            std::vector<Character*> getFighers();
            Character* replaceEnemy(Team* enemyTeam);
            //tidy
            Team(const Team &) = delete;
            Team &operator=(const Team &) = delete;
            Team(Team &&) = delete;
            Team &operator=(Team &&) = delete;

    };
}







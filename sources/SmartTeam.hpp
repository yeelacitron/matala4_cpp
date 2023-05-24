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
#include "Team.hpp"
namespace ariel{
    class SmartTeam: public Team{
        private:

            
        public:
            SmartTeam(Character * leader);
            void attack(Team *other);
            void attackInOrder(Character* enemy,Team *other);
            Character* findEnemy();

    };
}
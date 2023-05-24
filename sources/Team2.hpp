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
    class Team2 : public Team{
        private:

            
        public:
            Team2(Character *leader);
            //~Team2()=default;
            
            void print() override;
            void attackInOrder(Character* enemy,Team *other) override;

    };
}
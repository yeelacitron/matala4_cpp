#pragma once
#include "Point.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
namespace ariel{
    class Character{
        private:
            Point location;
            int hit_points;
            std::string name;
            bool inTeam;

        public:
            Character(std::string name,Point location,int hit_points);
            virtual ~Character() = default;
            bool isAlive() const;
            double distance(const Character *other) const;
            void hit(int hit_point);
            std::string getName() const;
            Point getLocation() const;
            void setLocation(Point pointer_to_binary_function);
            virtual std::string print()=0;
            int getHitPoints() const;
            bool isInTeam() const;
            void setInTeam(bool bol);
            //tidy
            Character(const Character &) = delete;
            Character &operator=(const Character &) = delete;
            Character(Character &&) = delete;
            Character &operator=(Character &&) = delete;
            
             
    };
}
#pragma once
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace ariel{
    class Ninja : public Character
    {
    private:
        const int speed;
    public:
        Ninja(std::string name,Point location,int hit_points,int speed);
        virtual ~Ninja() override =default;
        std::string print() override;
        void move(Character* enemy);
        void slash(Character* enemy);
        virtual int getSpeed() const=0;
        void ninjaMove(Character *enemy);
        //tidy
        Ninja(const Ninja &) = delete;
        Ninja &operator=(const Ninja &) = delete;
        Ninja(Ninja &&) = delete;
        Ninja &operator=(Ninja &&) = delete;
    };
}




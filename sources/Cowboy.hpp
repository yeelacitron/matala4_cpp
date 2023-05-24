#pragma once
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace ariel{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(std::string name,Point location);
        ~Cowboy() override =default;
        void shoot(Character *enemy);
        std::string print() override;
        bool hasboolets() const;
        void reload();
        int getNumBullets() const;
        void cowboyMove(Character *enemy);
        //tidy
        Cowboy(const Cowboy &) = delete;
        Cowboy &operator=(const Cowboy &) = delete;
        Cowboy(Cowboy &&) = delete;
        Cowboy &operator=(Cowboy &&) = delete;
    };

}
#pragma once
#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
namespace ariel{
    class TrainedNinja : public Ninja
    {
    private:
        /* data */
    public:
        TrainedNinja(std::string name,Point point);
        ~TrainedNinja()=default;
        int getSpeed() const override;
    };
}



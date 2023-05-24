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
    class YoungNinja : public Ninja
    {
    private:
        /* data */
    public:
        YoungNinja(std::string name,Point point);
        ~YoungNinja()=default;
        int getSpeed() const override;

    };
}
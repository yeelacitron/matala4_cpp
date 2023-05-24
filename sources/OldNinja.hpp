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
    class OldNinja : public Ninja
    {
    private:
        /* data */
    public:
        OldNinja(std::string name,Point point);
        ~OldNinja() override =default;
        int getSpeed() const override;

    };
}
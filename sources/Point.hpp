#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#pragma once

namespace ariel{
    class Point{
        private:
            double x_coordinate;
            double y_coordinate;
        public:
            Point(double x_coordinate,double y_coordinate);
            double distance(const Point &other) const;
            static Point moveTowards(const Point &src,const Point &dst, double distance);
            double getX() const;
            double getY() const;
            std::string print();
            friend bool operator==(const Point& point_2, const Point& point_1);


    };
}
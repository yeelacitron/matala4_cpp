#include "Point.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include<math.h>
using namespace std;
namespace ariel{

    Point::Point(double x_coordinate,double y_coordinate):x_coordinate(x_coordinate),y_coordinate(y_coordinate){

    }
    
    double Point::distance(const Point &other) const{
        double X = this->x_coordinate - other.x_coordinate;
        double Y = this->y_coordinate - other.y_coordinate;;
        return sqrt(X*X + Y*Y);
    }
    Point Point::moveTowards(const Point &src,const Point &dst, double distance){
        if(distance<0){
            throw invalid_argument("distance can't be minus");
        }
        double currentDistance = src.distance(dst);
        if (currentDistance <= distance) {
            // The target point is already within the given distance
            return dst;
        } 
        // Calculate the direction towards the target point
        double dx = dst.x_coordinate - src.x_coordinate;
        double dy = dst.y_coordinate - src.y_coordinate;
        
        // Normalize the direction vector
        dx /= currentDistance;
        dy /= currentDistance;
        
        // Calculate the new point within the given distance
        float newX = src.x_coordinate + dx * distance;
        float newY = src.y_coordinate + dy * distance;
        
        return Point(newX, newY);
    }
        
    
    double Point::getX() const{
        return x_coordinate;
    }
    double Point::getY() const{
        return y_coordinate;
    }
    bool operator==(const Point& point_1, const Point& point_2){
        if(point_1.x_coordinate!=point_2.x_coordinate){
            return false;
        }
        if(point_1.y_coordinate!=point_2.y_coordinate){
            return false;
        }
        return true;
    }
    string Point::print(){
        return "("+to_string(x_coordinate)+","+to_string(y_coordinate)+")";
    }
    
}
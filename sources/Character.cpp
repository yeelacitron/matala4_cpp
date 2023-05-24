#include "Character.hpp"



using namespace std;
namespace ariel{
    Character::Character(std::string name,Point location,int hit_points):name(name),location(location),hit_points(hit_points)\
    ,inTeam(false){}
 

    bool Character::isAlive() const{
        return (this->hit_points>0);
    }
    double Character::distance(const Character *other) const{
        return this->location.distance(other->location);
    }
    void Character::hit(int hit_point){
        if(hit_point<0){
            throw invalid_argument("argiment must be an positive number");
        }
        this->hit_points-=hit_point;
    }
    string Character::getName() const{
        return this->name;
    }
    Point Character::getLocation() const{
        return this->location;
    }
    void Character::setLocation(Point point){
        this->location = point;
    }
    int Character::getHitPoints() const{
        return this->hit_points;
    }
    bool Character::isInTeam() const{
        return inTeam;
    }
    void Character::setInTeam(bool bol){
        inTeam = bol;
    }


}
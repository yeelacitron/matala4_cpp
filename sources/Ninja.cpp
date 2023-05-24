#include "Ninja.hpp"
using namespace std;
namespace ariel{

    Ninja::Ninja(string name,Point location,int hit_points,int speed):Character(name,location,hit_points),speed(speed){

    }
    
    string Ninja::print() {
        if(this->isAlive()){
            return "name: "+this->getName()+",location: "+this->getLocation().print()+",hit points: "+to_string(this->getHitPoints());
        }
        else{
            return "name: N(" + this->getName() + ") point at: "+ this->getLocation().print();
        }    
        
    }
    void Ninja::move(Character* enemy){
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),speed));
        
    }
    void Ninja::slash(Character* enemy){
        if(!enemy->isAlive()){
            throw runtime_error("can't slash dead Character");
        }
        if(!this->isAlive()){
            throw runtime_error("dead ninja can't attack");
        }
        if(this==enemy){
            throw runtime_error("no self hurm");
        }
        if(this->distance(enemy)<1){
            enemy->hit(40);
        }
        
    }
    void Ninja::ninjaMove(Character *enemy){
        if(this->distance(enemy)<1){
            slash(enemy);
        }
        else{
            move(enemy);
        }
    }
    
}
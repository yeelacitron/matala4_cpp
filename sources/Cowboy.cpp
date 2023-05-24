#include "Cowboy.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;
namespace ariel{
    Cowboy::Cowboy(std::string name,Point location):Character(name,location,110),bullets(6){

    }
    void Cowboy::shoot(Character *enemy){
        if(!enemy->isAlive()){
            throw runtime_error("can't shoot dead Character");
        }
        if(!this->isAlive()){
            throw runtime_error("dead cowboy can't attack");
        }
        if(this==enemy){
            throw runtime_error("no self hurm");
        }
        if(this->hasboolets()){
            enemy->hit(10);
            this->bullets--;
        }
    }
    string Cowboy::print(){
        if(this->isAlive()){
            return "name: "+this->getName()+",location: "+this->getLocation().print()+",hit points: "+to_string(this->getHitPoints());
        
        }
        else{
            return "name: C(" + this->getName() + ") point at: "+ this->getLocation().print();
        }
    }
    bool Cowboy::hasboolets() const{
        return (this->bullets>0);
    }
    void Cowboy::reload(){
        if(!this->isAlive()){
            throw runtime_error("can't reload gun to dead cowboy");
        }
        this->bullets=6;
        
    }
    int Cowboy::getNumBullets() const{
        return this->bullets;
    }
    void Cowboy::cowboyMove(Character *enemy){
        if(this->hasboolets()){
           this->shoot(enemy);
        }
        else{
            this->reload();
        }
    }
}
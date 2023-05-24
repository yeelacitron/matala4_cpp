#include "TrainedNinja.hpp"
using namespace std;
namespace ariel{

    TrainedNinja::TrainedNinja(std::string name,Point point):Ninja(name,point,120,12){
    }
    int TrainedNinja::getSpeed() const{
        return 12;
    }
}
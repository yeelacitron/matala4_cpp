#include "OldNinja.hpp"
using namespace std;
namespace ariel{

    OldNinja::OldNinja(std::string name,Point point):Ninja(name,point,150,8){
    }
    int OldNinja::getSpeed() const{
        return 8;
    }

}

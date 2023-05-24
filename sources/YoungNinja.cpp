#include "YoungNinja.hpp"
using namespace std;
namespace ariel{

    YoungNinja::YoungNinja(std::string name,Point point):Ninja(name,point,100,14){
    }
    int YoungNinja::getSpeed() const{
        return 14;
    }

}

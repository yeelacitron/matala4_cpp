#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
using namespace std;
using namespace ariel;
TEST_SUITE("Point tests")
{
    TEST_CASE("Point constractor")
    {
        CHECK_NOTHROW(Point(32.3, 44));
        CHECK_NOTHROW(Point(0, 0));
        CHECK_NOTHROW(Point(-1, -2));
        Point a(32.3, 44);
        CHECK_EQ(a.getX(), 32.4);
        CHECK_EQ(a.getY(), 44);
    }
    TEST_CASE("Point distance()")
    {
        Point a(32.3, 44), b(1.3, 3.5), c(1, 0), d(3, 0), e(3, 4), f(6, 8);
        CHECK_NOTHROW(a.distance(b));
        CHECK(a.distance(b) == b.distance(a));
        CHECK_EQ(c.distance(d), 2.0);
        CHECK_EQ(e.distance(f), 5);
        CHECK_EQ(a.distance(a), 5);
    }
    TEST_CASE("Point moveTowards()")
    {
        Point a(32.3, 44), b(1.3, 3.5), c(1, 0), d(3, 0), e(3, 4), f(6, 8);
        CHECK_NOTHROW(Point::moveTowards(a, b, 1));
        CHECK_THROWS(Point::moveTowards(a, b, -1));
        CHECK_EQ(Point::moveTowards(c, d, 1), Point(2, 0));
        CHECK_EQ(Point::moveTowards(a, b, 60), b);
    }
}
TEST_SUITE("Character tests")
{
    TEST_CASE("Cowboy constractor and function at a start of a game")
    {
        CHECK_NOTHROW(Cowboy("Bill", Point(1.4, -65.7)));
        Cowboy b("Bill", Point(1.4, -65.7));
        CHECK(b.hasboolets());
        CHECK_EQ(b.getName(), "bill");
        CHECK_EQ(b.getLocation(), Point(1.4, -65.7));
        CHECK(b.isAlive());
        CHECK_EQ(b.distance(b), 0);
        CHECK_EQ(b.getHitPoints(), 110);
    }
    TEST_CASE("YoungNinja constractor and function at a start of a game")
    {
        CHECK_NOTHROW(YoungNinja("fu", Point(1.4, -65.7)));
        YoungNinja b("fu", Point(1.4, -65.7));
        CHECK_EQ(b.getSpeed(), 14);
        CHECK_EQ(b.getName(), "fu");
        CHECK_EQ(b.getLocation(), Point(1.4, -65.7));
        CHECK(b.isAlive());
        CHECK_EQ(b.distance(b), 0);
        CHECK_EQ(b.getHitPoints(), 100);
    }
    TEST_CASE("TrainedNinja constractor and function at a start of a game")
    {
        CHECK_NOTHROW(TrainedNinja("fu", Point(1.4, -65.7)));
        TrainedNinja b("fu", Point(1.4, -65.7));
        CHECK_EQ(b.getSpeed(), 12);
        CHECK_EQ(b.getName(), "fu");
        CHECK_EQ(b.getLocation(), Point(1.4, -65.7));
        CHECK(b.isAlive());
        CHECK_EQ(b.distance(b), 0);
        CHECK_EQ(b.getHitPoints(), 120);
    }
    TEST_CASE("YoungNinja constractor and function at a start of a game")
    {
        CHECK_NOTHROW(OldNinja("fu", Point(1.4, -65.7)));
        OldNinja b("fu", Point(1.4, -65.7));
        CHECK_EQ(b.getSpeed(), 10);
        CHECK_EQ(b.getName(), "fu");
        CHECK_EQ(b.getLocation(), Point(1.4, -65.7));
        CHECK(b.isAlive());
        CHECK_EQ(b.distance(b), 0);
        CHECK_EQ(b.getHitPoints(), 150);
    }
}

TEST_SUITE("Teams tests")
{
    TEST_CASE("Team initialization")
    {
        Cowboy *cowboy = new Cowboy("bill", Point(1, -2.7));
        OldNinja *old = new OldNinja("fu", Point(1.4, -65.7));
        TrainedNinja *trained = new TrainedNinja("sushi", Point(0, 12));
        YoungNinja *young = new YoungNinja("wasabi", Point(-5.8, 0));
        Team a(cowboy);
        CHECK_EQ(a.stillAlive(), 1);
        // Checks that all the Character can be add to a Team
        CHECK_NOTHROW(Team a(cowboy));
        CHECK_NOTHROW(a.add(old));
        CHECK_NOTHROW(a.add(young));
        CHECK_NOTHROW(a.add(trained));
        CHECK_EQ(a.stillAlive(), 4);
        // Can't add a Character that is in the Team
        CHECK_THROWS(a.add(cowboy));
        Cowboy *b_cowboy = new Cowboy("billy", Point(1, -2.7));
        Team b(b_cowboy);
        // Can't add the same Character into two different Teams
        CHECK_THROWS(a.add(young));
        //Test that we can't add more then 10 Character in one team
        for(int i=0; i<9;i++){
            OldNinja *old = new OldNinja("fu", Point(1.4, -65.7));
            b.add(old);
        }
        TrainedNinja *lastAdd = new TrainedNinja("sushi", Point(0, 12));
        CHECK_THROWS(b.add(lastAdd));
    }
    TEST_CASE("Team2 initialization")
    {
        Cowboy *cowboy = new Cowboy("bill", Point(1, -2.7));
        OldNinja *old = new OldNinja("fu", Point(1.4, -65.7));
        TrainedNinja *trained = new TrainedNinja("sushi", Point(0, 12));
        YoungNinja *young = new YoungNinja("wasabi", Point(-5.8, 0));
        Team2 a(cowboy);
        CHECK_EQ(a.stillAlive(), 1);
        // Checks that all the Character can be add to a Team
        CHECK_NOTHROW(Team2 a(cowboy));
        CHECK_NOTHROW(a.add(old));
        CHECK_NOTHROW(a.add(young));
        CHECK_NOTHROW(a.add(trained));
        CHECK_EQ(a.stillAlive(), 4);
        // Can't add a Character that is in the Team
        CHECK_THROWS(a.add(cowboy));
        Cowboy *b_cowboy = new Cowboy("billy", Point(1, -2.7));
        Team2 b(b_cowboy);
        // Can't add the same Character into two different Teams
        CHECK_THROWS(a.add(young));
        //Test that we can't add more then 10 Character in one team
        for(int i=0; i<9;i++){
            OldNinja *old = new OldNinja("fu", Point(1.4, -65.7));
            b.add(old);
        }
        TrainedNinja *lastAdd = new TrainedNinja("sushi", Point(0, 12));
        CHECK_THROWS(b.add(lastAdd));
    }
    TEST_CASE("SmartTeam initialization")
    {
        Cowboy *cowboy = new Cowboy("bill", Point(1, -2.7));
        OldNinja *old = new OldNinja("fu", Point(1.4, -65.7));
        TrainedNinja *trained = new TrainedNinja("sushi", Point(0, 12));
        YoungNinja *young = new YoungNinja("wasabi", Point(-5.8, 0));
        SmartTeam a(cowboy);
        CHECK_EQ(a.stillAlive(), 1);
        // Checks that all the Character can be add to a Team
        CHECK_NOTHROW(SmartTeam a(cowboy));
        CHECK_NOTHROW(a.add(old));
        CHECK_NOTHROW(a.add(young));
        CHECK_NOTHROW(a.add(trained));
        CHECK_EQ(a.stillAlive(), 4);
        // Can't add a Character that is in the Team
        CHECK_THROWS(a.add(cowboy));
        Cowboy *b_cowboy = new Cowboy("billy", Point(1, -2.7));
        SmartTeam b(b_cowboy);
        // Can't add the same Character into two different Teams
        CHECK_THROWS(a.add(young));
        //Test that we can't add more then 10 Character in one team
        for(int i=0; i<9;i++){
            OldNinja *old = new OldNinja("fu", Point(1.4, -65.7));
            b.add(old);
        }
        TrainedNinja *lastAdd = new TrainedNinja("sushi", Point(0, 12));
        CHECK_THROWS(b.add(lastAdd));
    }
}
TEST_SUITE("Ninjas moves"){
    TEST_CASE("move()")
    {
        OldNinja *old = new OldNinja("fu", Point(0, 0));
        TrainedNinja *trained = new TrainedNinja("sushi", Point(0, 0));
        YoungNinja *young = new YoungNinja("wasabi", Point(0, 0));
        YoungNinja *enemy = new YoungNinja("enemy",Point(0, 80));
        old->move(enemy);
        CHECK_EQ(old->getLocation(),Point(0,8));
        trained->move(enemy);
        CHECK_EQ(trained->getLocation(),Point(0,12));
        young->move(enemy);
        CHECK_EQ(young->getLocation(),Point(0,14)); 
        enemy->move(old);
        CHECK_EQ(young->getLocation(),Point(0,66)); 
    }
    TEST_CASE("slush()")
    {
        OldNinja *old = new OldNinja("fu", Point(0, 1));
        TrainedNinja *trained = new TrainedNinja("sushi", Point(0, 1.5));
        YoungNinja *young = new YoungNinja("wasabi", Point(0, 2));
        Cowboy *enemy = new Cowboy("enemy",Point(0, 0.75));
        //Should'nt reduce point from young becuase he is too far from old
        old->slash(young);
        CHECK_EQ(young->getHitPoints(),100);
        //Should reduce 40 point from young
        trained->slash(young);
        CHECK_EQ(young->getHitPoints(),60);
        trained->slash(young);
        trained->slash(young);
        CHECK_FALSE(young->isAlive());
        CHECK_THROWS(trained->slash(young));
        //Ninja shuold slash Cowboy
        old->slash(enemy);
        CHECK_EQ(enemy->getHitPoints(),70);
    }
    TEST_CASE("hit()"){
        OldNinja *old = new OldNinja("fu", Point(0, 1));
        TrainedNinja *trained = new TrainedNinja("sushi", Point(0, 1.5));
        YoungNinja *young = new YoungNinja("wasabi", Point(0, 2));    
        CHECK_NOTHROW(old->hit(80));   
        young->hit(40);
        CHECK_EQ(young->getHitPoints(),60);
    }
}
TEST_SUITE("Cowboys moves"){
    TEST_CASE("shoot()")
    {
        Cowboy *cowboy1 = new Cowboy("enemy",Point(0, 0.75));
        Cowboy *cowboy2 = new Cowboy("enemy",Point(0, 0.75));
        for(int i =1;i<=5;i++){
            cowboy1->shoot(cowboy2);
            CHECK(cowboy1->hasboolets());
            CHECK(cowboy2->isAlive());
            CHECK_EQ(cowboy2->getHitPoints(),100-(i*10));
            CHECK_EQ(cowboy1->getNumBullets(),6-i);
        }
        cowboy1->shoot(cowboy2);
        CHECK_FALSE(cowboy1->hasboolets());
        CHECK_EQ(cowboy1->getNumBullets(),0);
        CHECK_THROWS(cowboy1->shoot(cowboy2));
        cowboy1->reload();
        CHECK_EQ(cowboy1->getNumBullets(),6);
        //after the for cowboy2 should die
        for(int i =1;i<=5;i++){
            cowboy1->shoot(cowboy2);
            CHECK(cowboy1->hasboolets());
            CHECK(cowboy2->isAlive());
            CHECK_EQ(cowboy1->getNumBullets(),6-i);
        }
        CHECK_FALSE(cowboy2->isAlive());
    }
}
TEST_CASE("Teams attackes"){
    YoungNinja young_t1("one_1",Point(0,0));
    OldNinja old_t1("two_1",Point(0,0.5));
    Cowboy cowboy_t1("three_1",Point(0.5,0));
    YoungNinja young_t2("one_2",Point(0.75,0));
    TrainedNinja trained("two_2",Point(0,0.75));
    Cowboy old_t2("three_2",Point(0,0.25));
    Team a(&young_t1);
    Team2 b(&young_t2);
    //check the leaders
    CHECK_EQ(a.getLeader()->getName(),"one_1");
    CHECK_EQ(b.getLeader()->getName(),"one_b");
    a.attack(&b);
    


}
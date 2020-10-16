/****************************************

* File Name : inheritance.cpp

* Creation Date : 07-10-2020

* Last Modified : Friday 16 October 2020 03:48:58 PM

* Created By :  Bhaskar Tallamraju

* page # 586, 591, 600  : look at interface.cpp
* Note:
* 1. Inheritance has a "is-a" relationshio. For example: Player is-a GameEntity
*****************************************/
#include <iostream>

using namespace std;
class GameEntity
{
public:
    GameEntity() { cout << "   GameEntity constructor called" << endl; };
    ~GameEntity() { cout << "   GameEntity destructor called" << endl; };
    void start() { cout << "   GameEntity Started " << endl; }
    void end() { cout << "   GameEntity ended " << endl; }
};

//Player is inherited from GameEntity. Player is-a type of GameEntity
class Player : public GameEntity
{
public:
    Player() { cout << "   Player constructor called" << endl; }
    ~Player() { cout << "   Player destructor called" << endl; }
    // overriding start. However end is the same as GameEntity
    void start() { cout << "   Player started " << endl; }
};

int main (int argc, char *argv[])
{
    cout << "Creating a new Player " << endl;
    Player *pl = new Player();
    pl->start();
    pl->end(); // should call functionality provided by base class
    cout << "Deleting the Player " << endl;
    delete pl;
    return 0;
}


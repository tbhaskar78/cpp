/****************************************

* File Name : cast.cpp

* Creation Date : 07-10-2020

* Last Modified : Friday 16 October 2020 08:07:52 AM

* Created By :  Bhaskar Tallamraju

* page # 167
*****************************************/
#include <iostream>

using namespace std;

class Sweets
{
public:
    void eatDesserts()
    {
        cout << " Love Desserts!" << endl;
    }
};

class Savoury
{
public:
    void eatSavoury()
    {
        cout << " Love Savoury!" << endl;
    }
};


/* Dynamic casting example classes */
class GameEntity
{
public:
    virtual void PrintDescription(){}
};

class Player : public GameEntity
{
public:
    void PrintDescription()
    {
        cout << " I am the Player " << endl;
    }
};

class Enemy : public GameEntity
{
};

// this takes in a pointer which should ideally be a constant
void testFunc(Player *ge)
{
    ge->PrintDescription();
}

int main (int argc, char *argv[])
{

    // 1. static cast
    //
    {
        cout << "STATIC CAST : " << endl;
        double f = 5.65f;
        int i = static_cast<int>(f);
        cout << " " << i << endl;
    }

    // 2. dynamic cast
    // checks if the casting is valid or not and does the right thing
    // Generally used when casting from a base class to derived or vice versa
    // Since it does some extra work, it has an overhead
    // Hence better than C casting which would not recognize this
    {
        cout << "DYNAMIC CAST : " << endl;
        Player *player = new Player(); 
        GameEntity *ActuallyEnemy = new Enemy();  // this can be done, because Enemy is implicity of type GameEntity as well
        GameEntity *ActuallyPlayer = player;

        Player *p0 = dynamic_cast<Player*>(ActuallyEnemy);
        if (p0 == nullptr)
        {
            cout << " dynamic cast did the right thing, it cannot cast Enemy to player" << endl;
        }
        else
        {
            cout << " dynamic cast : oops " << endl;
        }
        Player *p1 = dynamic_cast<Player*>(ActuallyPlayer);
        if (p1 != nullptr)
        {
            cout << " dynamic cast did the right thing, it recognizes that player is actually getting cast to player" << endl;
        }
        else
        {
            cout << " dynamic cast : oops " << endl;
        }
        delete player;
        delete ActuallyEnemy;
    }

    // 3. reinterpret cast
    // can cast one pointer to another without any checks, and is very dangerous because of this
    {
        cout << "REINTERPRET CAST : " << endl;
        Savoury *sy = new Savoury;
        Sweets *st = new Sweets;

        st = reinterpret_cast<Sweets*>(sy);  // st is now sy but it is reinterpreted as Sweets class
        st->eatDesserts();
    }

    // 4. const cast
    // this is used to cast away the constness of a pointer
    {
        cout << "CONST CAST : " << endl;
        const Player *c = new Player(); 
        
        //testFunc(c);  // this will throw an error, cannot convert from const pointer to non const pointer
        
        //However, we can remove the constness of c by const_cast and pass cp
        Player *cp = const_cast<Player*>(c);
        testFunc(cp);
        
    }
    
}

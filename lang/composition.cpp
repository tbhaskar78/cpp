/****************************************

* File Name : composition.cpp

* Creation Date : 07-10-2020

* Last Modified : Friday 16 October 2020 03:36:19 PM

* Created By :  Bhaskar Tallamraju

* Notes:
* 1. Composition has a "has-a" relationship. 
* for example: Car has a door; Car has a window; Car has an engine
*****************************************/
#include <iostream>

using namespace std;

class Wheel
{
public:
    void inflate(int psi) const {}
};

class Window
{
public:
    bool rollup(float height) { cout << "Window rolled up " << endl; return true; }
    bool rolldown(float height) { cout << "Window rolled down " << endl; return true; }
};

class Door
{
public:
    Window window;
    bool open() { cout << "door open" << endl; return true; };
    bool close() { cout << "door closed " << endl;  return true; };
};

class Engine
{
private:
    int HorsePower;
public:
    void start() {cout << "engine started " << endl; }
    void accelerate (float acceleration) {}
};

// Car class has-a relationship with all of the underlying parts: which is COMPOSITION
class Car
{
public:
    Car() {}
    ~Car() {}
    Door leftDoor, rightDoor;
    Engine engine;
    Wheel wheel;
};

int main (int argc, char *argv[])
{
    Car car;
    car.leftDoor.close();
    car.leftDoor.window.rollup(22.5);
    car.engine.start();

    return 0;
}


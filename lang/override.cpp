/****************************************

* File Name : abstractClass.cpp

* Creation Date : 16-10-2020

* Last Modified : Friday 01 January 2021 08:24:52 PM

* Created By :  Bhaskar Tallamraju

*Note:
* 1. Abstract class is a class with virtual functions and atleast one pure virtual function that
* makes the class not instantiable
*****************************************/
#include <iostream>
#include <string>

using namespace std;

class Food
{
public:
    //virtual string getName() = 0;
    virtual string getName() { return "Food"; }
};

// Inheritance only
class Sweets : public Food
{
private:
    string m_Name;
public:
    // constructor
    Sweets(const string& name) 
        : m_Name(name) {}

    // virtual function override
    string getName() override { return m_Name; }
};

void Print(Food* v)
{
    cout << v->getName() << endl;
}

int main (int argc, char *argv[])
{
    Food *f = new Food();
    Print(f);

    Sweets *s = new Sweets("Desserts");
    Print(s);

    Food *f2 = s;
    // without virtual in base class and override in derived, this would print Food, instead of Dessert
    Print(f2);

}


/****************************************

* File Name : abstractClass.cpp

* Creation Date : 16-10-2020

* Last Modified : Friday 01 January 2021 08:39:11 PM

* Created By :  Bhaskar Tallamraju

*Note:
* 1. Abstract class is a class with virtual functions and atleast one pure virtual function that
* makes the class not instantiable
*****************************************/
#include <iostream>
#include <string>

using namespace std;

// Abstract class, as this forces the derived classes to have an implementation
class Food
{
public:
    Food() { cout << " Food Constructor called " << endl; }
    // always good to have virtual destructor in base class to avoid any
    // potential memory leaks, watch cherno virtual destructor
    virtual ~Food() { cout << " Food Destructor called " << endl; }
    virtual string type() = 0;
    virtual int price() = 0;
};

class Spicy : public Food
{
private:
    int m_price;
    string m_name;
public:
    // constructor
    Spicy(const string &name, int price)
    : m_price(price), m_name(name) { cout << " Spicy Constructor called " << endl; }
    ~Spicy() { cout << " Spicy Destructor called " << endl; }

    string type() override { return "I am Spicy Food"; }
    int price() override { return m_price; }
};

class Sweets : public Food
{
private:
    int m_price;
    string m_name;
public:
    // constructor
    Sweets(const string &name, int price)
    : m_price(price), m_name(name) { cout << " Sweets Constructor called " << endl; }
    ~Sweets() { cout << " Sweets Destructor called " << endl; }

    string type() override { return "I am Spicy Food"; }
    int price() override { return m_price; }
};

int main (int argc, char *argv[])
{
    Sweets *sw = new Sweets("Desserts", 100);
    Spicy *sp = new Spicy("Hot", 200);

    cout << "Type is " << sw->type() << endl;
    cout << "Price is " << sw->price() << endl;
    cout << "Type is " << sp->type() << endl;
    cout << "Price is " << sp->price() << endl;

    delete sw;
    delete sp;
}


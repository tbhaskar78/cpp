/****************************************

* File Name : virtual.cpp

* Creation Date : 07-10-2020

* Last Modified : Friday 16 October 2020 12:36:06 PM

* Created By :  Bhaskar Tallamraju

* page # 632, 637, 640
* Notes:
* 1. Interface is generally a class with all pure virtual functions
* 2. Cannot be instantiated
* 3. Derived classes are forced to implement the virtual functions
*****************************************/
#include <iostream>

using namespace std;

class IEntity
{
public:
    IEntity()  { cout << "   IEntity constructor " << endl; }

    virtual string& getName() = 0;
    virtual int &getInt() = 0;
    virtual char &getChar() = 0;
    virtual float &getFloat() = 0;
};

class Derived1 : public IEntity
{
private:
    int a;
    float f;
    char c;
    string name;
public:
    Derived1() { cout << "   Derived1 constructor " << endl; }  //default constructor has to be included
    ~Derived1() { cout << "   Derived1 destructor " << endl; }
    Derived1(const string &nm, const int& i, const float& fl, const char& ch)
        : name(nm), a(i), f(fl), c(ch) { cout << "   Derived1 constructor : special " << endl; }

    // overriding or implementing all functions from the Interface
    string& getName() override
    {
        return name;
    }
    int& getInt() override
    {
        return a;
    }
    float& getFloat() override
    {
        return f;
    }
    char& getChar() override
    {
        return c;
    }
};

class Derived2 : public Derived1
{
private:
    string m_Name;
public:
    Derived2()
      : m_Name("Derived2") { cout << "   Derived2 constructor " << endl; }
    ~Derived2() { cout << "   Derived2 destructor " << endl; }

    // just overriding getName
    string& getName() override
    {
        return m_Name;
    }

};


int main (int argc, char *argv[])
{
    //IEntity ie;  This will throw an error, as it is an interface class
    cout << "Init Derived1" << endl;
    Derived1 *d = new Derived1("Hello", 10, 10.11, 't');

    cout << d->getName() << " " << d->getInt() << endl;

    cout << "Init Derived2" << endl;
    Derived2 *d2 = new Derived2();
    cout << d2->getName() << endl;

    delete d;
    delete d2;

    return 0;
}


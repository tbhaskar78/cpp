/****************************************

* File Name : bindings.cpp

* Creation Date : 15-10-2020

* Last Modified : Friday 16 October 2020 10:16:50 AM

* Created By :  Bhaskar Tallamraju

* Note:
* 1. structured bindings was introduced in c++17 
* 2. this takes care of multiple returns from a function
*****************************************/
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

struct Persons
{
    string name;
    int age;
};

struct Persons PersonStat()
{
    return { "Bhaskar", 40 };
}

tuple<string, int> Person()
{
    return { "Bhaskar", 40 };
}

int main (int argc, char *argv[])
{
    // accessing multiple returns
    
    //1. Using tie
    string name1;
    int age1;
    tie(name1, age1) = Person();
    cout << "Using Ties \n Name: " << name1 << " Age: " << age1 << endl;

    //2. Using tuple
    auto person = Person();
    string& name2 = get<0>(person);
    int age2 = get<1>(person);
    cout << "Using tuple get \n Name: " << name2 << " Age: " << age2 << endl;

    //3. Using structure, looks clean as well
    struct Persons p = PersonStat();
    cout << "Using structure \n Name: " << p.name << " Age: " << p.age << endl;

    //4. Structured binding : are much cleaner way
    auto[name, age] = Person();
    cout << "Using structured binding \n Name: " << name << " Age: " << age << endl;
}


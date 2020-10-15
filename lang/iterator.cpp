/****************************************

* File Name : iterator.cpp

* Creation Date : 07-10-2020

* Last Modified : Friday 09 October 2020 01:32:00 PM

* Created By :  Bhaskar Tallamraju

*****************************************/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
void iterateVector(void)
{
    vector<int> vInt = { 1, 2, 3, 4, 5 };

    /* there are 3 types of iterators in vectors */

    // for loop, standard way 
    for (int i = 0; i < vInt.size(); i++)
    {
        cout << vInt[i] << endl;
    }

    // range based
    cout << endl;
    for (auto it : vInt)
    {
        cout << it << endl;
    }

    // iterator based
    cout << endl;
    // use using  to simplify "for (vector<int>::iterator it = vInt.begin(); " : it is like typedef
    using vectorIt = vector<int>;
    using vectorIterator = vectorIt::iterator;
    for (vectorIterator it = vInt.begin(); 
         it != vInt.end(); it++) // note "it != vInt.end()" and not less than vInt.end()
    {
        cout << *it << endl;
    }
}

void iterateMap(void)
{
    // create an unordered map string to int
    unordered_map<string, int> uMap;
    uMap["Bhaskar"] = 10;
    uMap["Test"] = 23;
    uMap["Ginger"] = 411;

    /* there are 3 types of iterators in cpp */
    cout << endl;
    // range based
    for (auto it : uMap)
    {
        auto& key = it.first;
        auto& value = it.second;
        cout << key << " = " << value << endl;
    }

    cout << endl;
    // iterator based
    using uMapIt = unordered_map<string, int>;
    for (uMapIt::iterator it = uMap.begin(); it != uMap.end(); it++)
    {
        auto& key = it->first;
        auto& value = it->second;
        cout << key << " = " << value << endl;
    }

    cout << endl;
    // for c++17 : structured binding, need to compile with -std=c++17
    for (auto [key, value]: uMap)
        cout << key << " = " << value << endl;
}

int main (int argc, char *argv[])
{
    cout << "iterate over a vector in 3 ways " << endl;
    iterateVector();

    cout << "iterate over an unordered map in 3 ways " << endl;
    iterateMap();
}


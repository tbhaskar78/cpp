/****************************************

* File Name : functionPointer.cpp

* Creation Date : 16-10-2020

* Last Modified : Friday 16 October 2020 09:28:14 AM

* Created By :  Bhaskar Tallamraju

*****************************************/
#include <iostream>
#include <vector>

using namespace std;

void PrintValue(int val)
{
    cout << "Value is " << val << endl;
}

void forEach(vector<int>& values, void(*func)(int))
{
    for (int value: values)
    {
        func(value);
    }
}


int main (int argc, char *argv[])
{
    vector<int> value = {1, 2, 3, 4, 5};
    void(*func)(int) = &PrintValue;  //take a function pointer which returns void and takes in an integer
    forEach(value, func);
}


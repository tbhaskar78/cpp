/****************************************

* File Name : lambda.cpp

* Creation Date : 15-10-2020

* Last Modified : Friday 16 October 2020 09:57:04 AM

* Created By :  Bhaskar Tallamraju
*
* Note:
* 1. Lambda is an anonymous function or a throwaway function
* 2. lambda is used when you want to pass a function that needs to do something later on
* 3. receive lambda as a function pointer (look at functionPointer.cpp)
* 4. start a lambda with [] which can capture local variables
* 5. next pass '(int value)' parameters inside round brackets
* 6. write the actual function inside curly braces
*****************************************/
#include <iostream>
#include <vector>

using namespace std;
 
void forEach(vector<int>& values, void(*func)(int))
{
    for (auto value: values)
    {
        func(value);
    }
}

int main (int argc, char *argv[])
{
    vector<int> values = {1, 2, 3, 4, 5, 6};

    // writing a lambda, start with []. The square brackets can take external variables passes by value, referencei '&', 
    // '=' all local variables, '&' all local variables by reference. In our case, we do not need to pass any value
    forEach(values, [](int value){ cout << "Value is " << value << endl; });


    // lambda which returns
    bool(*check)(int, int) = [](int val1, int val2){ if (val1 > val2) return false; else return true; };
    cout << boolalpha;  // to print false or true instead of 0 or 1
    cout << check(11, 9) << endl;
    cout << check(9, 11) << endl;

    // lambda which captures all variables by value
    {
        int a = 10;
        float f = 11.119;
        auto glambda = [=]() { cout << "Value of a: " << a << " | Value of f: " << f << endl; };
        glambda();
    }

    // lambda which captures all variables by reference
    {
        int a = 10;
        float f = 11.119;
        // passed by reference, change the value now
        auto glambda = [&]() { cout << "Value of a: " << a << " | Value of f: " << f << endl; a = 20; f = 12.128; };
        glambda();
        // changed value should reflect
        cout << "Value of a: " << a << " | Value of f: " << f << endl;
    }

    // lambda which captures two variables by reference
    {
        int a = 10;
        float f = 11.119;
        // passed by reference, change the value now
        auto glambda = [&](auto &a, auto &f) { cout << "Value of a: " << a << " | Value of f: " << f << endl; a = 21; f = 13.128; };
        glambda(a, f);
        // changed value should reflect
        cout << "Value of a: " << a << " | Value of f: " << f << endl;
    }
}


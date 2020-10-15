/****************************************

* File Name : globalscope.cpp

* Creation Date : 07-10-2020

* Last Modified : Wednesday 07 October 2020 08:59:54 PM

* Created By :  Bhaskar Tallamraju

* page # 253, 265(?)
* Note: global scope variable and functions need to be accessed with a double colon (::)
*****************************************/
#include <iostream>

using namespace std;

// Global variables and function
int a = 99;

void f()
{
    cout << "global function, int a = " << a << endl;
}

class test 
{
    int a;
public:
    void f();
};

void test::f()
{
    a = 100;
    cout << "Testing class function, int a = " << a << endl;
    cout << "global int a = " << ::a << ". Now modifying it to 299 " << endl;
    ::a = 299;     // global scope 
    ::f();     // global scope 
}

int main (int argc, char *argv[])
{
    test t;
    t.f();

}


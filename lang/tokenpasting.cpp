/****************************************

* File Name : tokenpasting.cpp

* Creation Date : 07-10-2020

* Last Modified : Friday 16 October 2020 10:41:52 AM

* Created By :  Bhaskar Tallamraju

* page # 396
*
* Note:
* 1. ## operator allows for concatenation
*****************************************/
#include <iostream>
#include <string>

using namespace std;

#define Concat(a,b) a ## b

// defined a global variable token9, in cout constructing token9 and printing its value
int token9 = 90;
int token10 = 100;
// single '#' prints the value and ## operator concatenates
#define Print(n) { cout << "token" #n " value is = " << token##n << endl; }
int main (int argc, char *argv[])
{
    unsigned int c = Concat(512, 1024);
    cout << c << endl;

    Print(9);
    Print(10);
}


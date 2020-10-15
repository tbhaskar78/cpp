/****************************************

* File Name : lvalue_rvalue.cpp

* Creation Date : 08-10-2020

* Last Modified : Thursday 08 October 2020 01:21:24 PM

* Created By :  Bhaskar Tallamraju

* Notes:
* 1. lvalue is also called locator value, since it has a location or memory associated with it
* 2. rvalue are temporary literals which do not have a location or memory associated with it
* 3. for example: int i = 10; // i  is lvalue and 10 is rvalue
* 4. rule is, if const ref is mentioned, it can accept both lvalue and rvalue
*    for example, const string&  can accept both lvalue and rvalue
*                 const int& can accept both lvalue and rvalue
*****************************************/
#include <iostream>

using namespace std;

void printString(const string& s) // will accept both lvalue and rvalue
{
    cout << "printing string " << s << endl;
}
void printInt(const int& i) // will accept both lvalue and rvalue
{
    cout << "printing int " << i << endl;
}

int& getValue() // can take rvalue now as return is ref to location
{
    static int val = 10;
    return val;
}

//overload readVal, that way we can distinguish between rvalue and lvalue passed
void readVal(int&& i) // will only read rvalue, does not need const ... interesting
{
    cout << "printing only rvalue " << i << endl;
}

void readVal(const int& i) // will read both lvalye and rvalue
{
    cout << "printing value " << i << endl;
}

int main (int argc, char *argv[])
{
    int j = 10;   // j is lvalue and 10 is rvalue

    string a = "Hello";
    string b = "World";
    string c = a+b;
    printString(a+b);  //a+b is an rvalue, since it is a temp literal and does not 
                       //have a memory associated with it
    printString(c);  //c is an lvalue

    int i = 11;
    printInt(10);  // passing rvalue 10 
    printInt(i);  // passing lvalue

    getValue() = 10; // works but doesn't make sense


    // automatically choose rvalue or lvalue 
    readVal(10); // will select rvalue version automatically
    readVal(i); // will select the function which can accept both rvalye and lvalue

    return 0;
}


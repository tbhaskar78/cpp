/****************************************

* File Name : passReference.cpp

* Creation Date : 07-10-2020

* Last Modified : Wednesday 07 October 2020 09:14:31 PM

* Created By :  Bhaskar Tallamraju

* page # 140, 451

* Note
* 1. references need to be initialized
* 2. references cannot be null 
* 3. one reference is initialized, it cannot be changed
*****************************************/
#include <iostream>

using namespace std;

class test
{
public:
    void f(int &);
    void c(const string& );
};

// arg passed by reference 
void test::f(int &r)
{
    cout << "val of passed variable is " << r << endl;
    r = 200;
}

// const string& can take passed char * or string
void test::c(const string &s)
{
    cout << "val of passed string is " << s << endl;
}

int main (int argc, char *argv[])
{
    int testVar = 100;
    int &r = testVar;  // create a reference
    string str = "Hello World";
    const char *cptr = "Bye World"; // passing this as arg to the same function
    test t;
    // pass by reference
    t.f(testVar);
    cout << "var now is " << testVar << endl;

    // t.c() accepts both const char * and string alike
    t.c(str);
    t.c(cptr);
}


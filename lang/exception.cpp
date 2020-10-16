/****************************************

* File Name : exception.cpp

* Creation Date : 07-10-2020

* Last Modified : Friday 16 October 2020 01:29:55 PM

* Created By :  Bhaskar Tallamraju

* Notes:
* 1. noexcept means the function will not throw an exception or it is okay to crash
* 2. throw() is equivalent to noexcept(true) .. means exception is thrown
* 3. Should stop using throw() which will be deprecated in C++20 
*****************************************/
#include <iostream>
#include <exception>

using namespace std;

// These are different ways of noexcept can be used in declaration
void function1() noexcept;              // no exception will be thrown
void function3() noexcept(true);        // no exception will be thrown
void function4() throw();               // no exception will be thrown
void function2() noexcept(false);       // EXCEPTION may be thrown

// define new exception
class MyException : public exception
{
public:
    const char* what() const throw ()
    {
        return "C++ Exception";
    }
};

double Division(int x)
{
    if (x == 0)
    {
        throw "Division by Zero";
    }
    return 10/x;
}

int main (int argc, char *argv[])
{
    double f = 0;
    try
    {
        f = Division(0);
    }
    catch(const char *e)
    {
        cout << e << endl;
    }


    // throw my custom exception
    try
    {
        throw MyException();
    }
    catch(MyException &e)
    {
        cout << "MyException caught : " << e.what() << endl;
    }

    return 0;
}



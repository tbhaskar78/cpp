#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void testfunc(void);
class Testfrnd;   // dummy declaration

class Test {
    // default private specifier
    int var1;
    char char2;
    string string3;
public:
    // friend
    friend void testfunc(void) ;
    friend class Testfrnd;

    // constructor
    Test()
    {
        cout << "I am in the constructor" << endl;
    }
    // destructor
    ~Test()
    {
        cout << "I am in the destructor" << endl;
    }
    // mutator accessors
    void var(int a) 
    {
        var1 = a;
    }
    int var(void) const
    {
        return var1;
    }
    void str(const string& s)
    {
        string3 = s;
    }
    string str(void) const
    {
        return string3;
    }
};

class Testfrnd {
public:
    void hello(void) 
    {
        Test test;
        test.string3 = "Am I a friend";
        cout << test.string3 << endl;
    }
};

void testfunc(void) 
{
    Test test;
    test.var1 = 100;
    test.string3 = "Bye Cruel world";
    cout << test.var1 << " " << test.string3 << endl;
}

int main(int argc, char *argv[])
{
    Test test;
    test.var(1999);

    test.str("Hello World, are you okay?");

    cout << test.var() << endl;
    cout << test.str() << endl;

    testfunc();

    Testfrnd testfrnd;
    testfrnd.hello();

}

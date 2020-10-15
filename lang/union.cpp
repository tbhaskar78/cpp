/****************************************

* File Name : union.cpp

* Creation Date : 07-10-2020

* Last Modified : Wednesday 07 October 2020 09:25:26 PM

* Created By :  Bhaskar Tallamraju

* page # 318, 322

* Notes:
* 1. UNION cannot be used as base class for inheritance
* 2. UNION is exactly same as a class, has constructor, destructor
*****************************************/
#include <iostream>

using namespace std;

union U
{
    int i;
    double f;
public:
    U(int a) 
    {
        cout << "in the int constructor " << endl;
        i = a;
    }
    U(double b) 
    {
        cout << "in the float constructor " << endl;
        f = b;
    }
    ~U()
    {
        cout << "in the destructor " << endl;
    }
    void readInt()
    {
        cout << "I am int function of a union " << i << endl;
    }
    void readFloat()
    {
        cout << "I am float function of a union " << f << endl;
    }
};

int main (int argc, char *argv[])
{
    U myInt(199);
    U myFloat(198.978654);

    myInt.readInt();
    myFloat.readFloat();
}


/****************************************

* File Name : deletearray.cpp

* Creation Date : 07-10-2020

* Last Modified : Monday 12 October 2020 10:31:22 AM

* Created By :  Bhaskar Tallamraju

* page # 225, 563, 
*****************************************/
#include <iostream>

using namespace std;

class Array
{
private:
    int *aPtr;
public:
    Array() : aPtr(nullptr) {} // default constructor
    Array(int size)
        : aPtr(nullptr)
    {
        if( aPtr == nullptr) 
        {
            cout << "creating a new of size elements " << endl; 
            aPtr = new int[size];   //ALLOCATING a pointer to an array
        }
    }
    ~Array() 
    { 
        cout << "deleting aPtr" << endl; 
        delete []aPtr;   //DELETING a pointer to an array
    }

};

int main (int argc, char *argv[])
{
    {
        Array a(10);
    }
}


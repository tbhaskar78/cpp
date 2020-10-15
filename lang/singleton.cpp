/****************************************

* File Name : singleton.cpp

* Creation Date : 12-10-2020

* Last Modified : Thursday 15 October 2020 05:09:03 PM

* Created By :  Bhaskar Tallamraju

* Notes:
* Singleton design pattern should 
* 1. allow no instantiations, hence the constructor should not be publicly accessible
* 2. have no copy constructor to avoid copy objects by mistake
* 3. provide a static instance, so no allocations are done
*****************************************/
#include <iostream>

using namespace std;

class Singleton
{
private:
    Singleton() {}   // private constructor, so no way to instantiate it

    // example data members
    int m_data1;
    int m_data2;
    char m_data3;

    static Singleton s_Instance;  // this declaration needs to be globally defined somewhere
public:
    Singleton(const Singleton &copiedObject) = delete;  //copy constructor marked delete, hence no way to copy
    ~Singleton() {}

    static Singleton& GetInstance()
    {
        return s_Instance;
    }

    int testFunc()
    {
        cout << "Test member function called" << endl;
        return 100;
    }

};

// static instance declaration does not need static
Singleton Singleton::s_Instance;  // definition for line 32

int main (int argc, char *argv[])
{
    // Singleton sInst;   // this will throw a compilation error, as there is no way to instantiate it
    Singleton& sInst = Singleton::GetInstance(); // be sure to take it as a reference
    auto& sInst2 = Singleton::GetInstance();  //be sure to take it as a reference
    cout << sInst.testFunc() << endl;
    
    return 0;
}


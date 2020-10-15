/****************************************

* File Name : singleton.cpp

* Creation Date : 12-10-2020

* Last Modified : Thursday 15 October 2020 05:17:13 PM

* Created By :  Bhaskar Tallamraju

* Notes:
* Singleton design pattern should 
* 1. allow no instantiations, hence the constructor should be private
* 2. mark copy constructor as delete to avoid object copy
* 3. provide a static instance, so no allocations can be done
*****************************************/
#include <iostream>

using namespace std;

// sample singleton Random number generator
class Random
{
private:
    Random() {}   // private constructor
    static Random randomInstance;
    float randomNumber = 0.5f;
public:
    ~Random() {}
    Random(const Random&) = delete;  // mark copy constructor as delete

    static Random& GetInstance()
    {
        return randomInstance;
    }
    float getRandomNumber()
    {
        return randomNumber;
    }
};

Random Random::randomInstance;

int main(int argc, char *argv[])
{
    Random& rInst = Random::GetInstance();
    cout << rInst.getRandomNumber() << endl;

    cout << Random::GetInstance().getRandomNumber() << endl;

    
    return 0;
}

/****************************************

 * File Name : template.cpp

 * Creation Date : 07-10-2020

 * Last Modified : Monday 12 October 2020 08:39:48 AM

 * Created By :  Bhaskar Tallamraju

 * page # 697
 *
 * Note: 
 * the template function will only be created by C++ if it is used, otherwise
 * it will not be used in the actual code. 
 *****************************************/
#include <iostream>

using namespace std;

// syntax for typename, T is template. 
// otherwise we would have to write an overloaded function for all 3 types
template<typename T>
void Print(T val)
{
    cout << val << endl;
}

int main (int argc, char *argv[])
{
    // type may be skipped, as C++ can deduce based on the value passed
    Print<float>(5.5f);
    Print(50999);
    Print("BHASKAR");
}


/****************************************

 * File Name : template.cpp

 * Creation Date : 07-10-2020

 * Last Modified : Monday 12 October 2020 09:54:30 AM

 * Created By :  Bhaskar Tallamraju

 * page # 697
 *
 * Note: 
 * typename and class in template are interchangeable for most cases
 *****************************************/
#include <iostream>

using namespace std;

//this can be used to create a dynamic array at runtime
template<int SIZE>
class Array
{
private:
    int m_Array[SIZE];
public:
    Array(){};
    ~Array(){};
    int getSize(void) const { return sizeof(m_Array)/sizeof(int) ; }
};

// template can take more than one templates as well
template<typename T, int SIZE>
class Array2
{
private:
    T m_Array[SIZE];
public:
    Array2() {}
    ~Array2() {}
    int getSize() const { cout << "sizeof type is " << sizeof(T) << " and array size "; return sizeof(m_Array)/sizeof(T); }
};

int main (int argc, char *argv[])
{
    // template for dynamic array size
    Array<100> a;
    cout << "Size in Array " << a.getSize() << endl;

    Array2<short, 100> a2;
    cout << "Size in Array2 " << a2.getSize() << endl;
}


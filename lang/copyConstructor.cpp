/****************************************

* File Name : copyConstructor.cpp

* Creation Date : 07-10-2020

* Last Modified : Thursday 15 October 2020 04:46:42 PM

* Created By :  Bhaskar Tallamraju

* page # 289, 304, 459 - 464, 472
*****************************************/
#include <iostream>
#include <cstring> // c header for string.h

using namespace std;

class String
{
private:
    char *m_Buffer;
    unsigned int m_Size;

public:
    // adding a copy constructor for deep copy, that means
    // allocate pointers again and copy the string correctly
    String (const String& copyObject)
    {
        cout << "Copy constructor called " << endl;
        m_Size = copyObject.m_Size;
        m_Buffer = new char[m_Size]();
        memcpy(m_Buffer, copyObject.m_Buffer, m_Size);
    }

    String(const char* str)
    {
        cout << "constructor called " << endl;
        m_Size = strlen(str);
        m_Buffer = new char[m_Size](); // () will initialize the char buffer with zeros
        memcpy(m_Buffer, str, m_Size); // null termination is guaranteed from above
    }

    ~String()
    {
        cout << "destructor called " << endl;
        delete []m_Buffer;
    }

    // operator overload for [] to manipulate index 
    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }


    friend ostream& operator<<(ostream &, const String& );
};

ostream& operator<<(ostream &stream, const String& str)
{
    stream << str.m_Buffer;  //m_Buffer is private member, needs to be friend 
    return stream;
}

void PrintStr(const String str)
{
    cout << str << endl;
}

// const to avoid it from being changed
void PrintStr2(const String& str)
{
    cout << str << endl;
}

int main (int argc, char *argv[])
{
    String str = "Hello World";

    String secondStr = str;  // making a copy of the str Object, will invoke default copy constructor
                             // which will do shallow copy, that means pointer dereference is not done and content not
                             // copied. This would mean both objects have pointers with the same address. During exit
                             // from scope, destructor will be called and will result in catastrophic result for
                             // secondStr, as the pointer would be freed in the first destructor of obj str.
                             // On Linux, it shows double free detected, as pointer was freed in the destructor of the
                             // first object, however since the same pointer address is used for another free in
                             // secondStr object, it throws this exception
                             

    PrintStr(str);           // this will cause a copy of object as well, since it is not taking reference in the parameter
    PrintStr2(secondStr);    //this does not involve a copy of object and hence is less expensive

    secondStr[0] = 'C';      // using operator [] overload to get reference of index into m_Buffer
    secondStr[1] = 'r';
    secondStr[2] = 'u';
    secondStr[3] = 'e';
    secondStr[4] = 'l';
    cout << secondStr << endl;

    cout << str << endl;     // cout will not know how to ostream it as String is user defined type
                             // needs overloading

}


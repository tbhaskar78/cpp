/****************************************

* File Name : uniqptr.cpp

* Creation Date : 07-10-2020

* Last Modified : Thursday 08 October 2020 01:06:05 PM

* Created By :  Bhaskar Tallamraju

* Notes:
* 1. unique pointer has low overhead, but cannot be copied
* 2. shared pointer has a bigger overhead as it allocates extra block. this block is called 
*    control block which holds the ref count
* 3. weak pointers are good when we want to check the pointer existence or read a few things
*    without owning the memory
*****************************************/
#include <iostream>
#include <memory>  // needed for smart pointers

using namespace std;

class testClass 
{
    public:
    testClass(const string& s)
    {
        cout << " Test Class constructor called for " << s << endl;
    }
    ~testClass()
    {
        cout << " Test Class destructor called " << endl;
    }
    void testfn()
    {
        cout << " this is a test function " << endl;
    }
};

int main (int argc, char *argv[])
{
    /* unique pointers will destroy once they go out of scope, let us try that 
     * Notes:
     * 1. unique pointer can live in a scope alone, as the scope is exited, the ptr is free'd
     * 2. unique pointers cannot be shared or copied anywhere. 
     * 3. cannot be assigned to any other pointer
     */
    {  // DUMMY SCOPE for unique pointer

        unique_ptr<testClass> uPtr = make_unique<testClass>("uniquePtr"); // this will allocate memory and call the constructor

        //unique_ptr<testClass> u0 = uPtr;  //POINTER cannot be copied, it will throw an error as 
                                            // copy constructor and copy assignment operator are 
                                            // both pointing to delete
        uPtr->testfn();

    } // exiting this scope here will invoke the destructor of the class

    cout << endl; 
    /* shared pointers will destroy once they go out of scope, but work on reference count
     * Notes:
     * 1. shared pointer can live in a scope alone, as the scope is exited, the ref count it decreased. 
     *    once the ref count is zero, the shared pointer is deleted 
     * 2. can be copied, which will increase the ref count
     */
    {  // DUMMY SCOPE for shared pointer
        shared_ptr<testClass> sPtr0;
        {  // DUMMY SCOPE FOR shared pointer

            shared_ptr<testClass> sPtr = make_shared<testClass>("sharedPtr"); //ref count = 1
            sPtr0 = sPtr;  // copy is allowed which will increase the ref count: ref count = 2
            sPtr->testfn();

        } // exiting this scope will reduce the ref count but not destroy the memory yet: ref count = 1
        cout << " Destructor not called yet " << endl;

    }  // final exit of scope will make ref count to zero and will destroy the mem and hence call destructor: ref count = 0

    cout << endl; 
    /* weak pointers will work with shared pointers, except they do not increase the ref count
     */
    {  // DUMMY SCOPE for shared pointer
        weak_ptr<testClass> wPtr;
        {  // DUMMY SCOPE FOR shared pointer

            shared_ptr<testClass> sPtr = make_shared<testClass>("sharedPtr->weakPtr"); // ref count = 1
            wPtr = sPtr;  // copy to weak ptr will not increase the ref count: ref count = 1
            sPtr->testfn();

        } // exiting this scope will reduce the ref count but not destroy the memory yet
        cout << " Destructor will be called before this, as weakPtr did not increase ref count  " << endl;

    }  // final exit of scope will make ref count to zero and will destroy the mem and hence call destructor


    return 0;
}


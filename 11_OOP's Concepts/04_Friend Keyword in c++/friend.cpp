// Frend Keyword in c++ :-

// 1) Friend is a keyword in c++ that is used to shere the information of a class that was previously
//     hidden.

// 2) for example the private members of a class are hidden from every other class and cannot
//    ve modified except through getters or setters. similarly, the protected members are hiddin
//    from all classes other than its childeren classes.
#include <iostream>
using namespace std;
class A
{
private:
    int x;

public:
    A(int val) : x(val){};

    int getX() const
    {
        return x;
    }

    void setX(int _val)
    {
        x = _val;
    }
    friend class B; // this is called friend class 
    friend void print(const A &); // this is called friend function 
};

class B
{
public:
    // i want to print class A data members inside the class b..
    void print(const A &a)
    {
        // cout<<a.getX()<<endl;
        cout << a.x << endl; // this will not print the value of x because of x is the private member of class A
                             // to print x we have to make Friend .
    }
};
 void print(const A&a){ // this function is a friend of class A 
    cout<<a.x<<endl;
 }
int main()
{
    A a(6);
    B b;
    b.print(a);
    print(a);
    return 0;
}
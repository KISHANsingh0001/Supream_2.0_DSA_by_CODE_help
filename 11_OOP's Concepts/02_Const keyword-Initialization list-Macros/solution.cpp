#include <iostream>
using namespace std;

class abc
{
    mutable int x; // 
    int *y;
    int z;

public:
// this is old type to create prerametrized constructor..
    abc(int _x, int _y, int _z = 0)
    {                                
        x = _x;+
        y = new int(_y);
        z = _z;
    }

// this is new type to create constructor that is called {intialization list}
//  abc(int _z , int _y , int _z=0): x(_x) , y(new int (_y)) , z(_z) {}

    int getX() const  // how to change the constant variable??              
    {                 // we can use mutable keyword
        x = 10;
        return x;
    }
    void setX(int _val)
    {
        x = _val;
    }
    int getY() const
    {
        return *y;
    }
    void setY(int _val)
    {
        *y = _val;
    }
    int getZ() const
    {
        return z;
    }
};

void printABC(const abc &a) // a srif const methods ko hi call karga
{
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}
int main()
{
    abc a(1, 2, 3);
    printABC(a);
    return 0;
}
int main2()
{
    const int x = 5; // x is constant
    // intialization can be done
    // but we cant re-assign a value.
    // cout<<x<<endl;

    // *************************************************************

    // 2. Const with pointers
    // const int *a = new int(2); // CONST data(we cant change the data) , NON CONST pointer(we can change the pointer)
    // int const *a = new int(2); // same like line no. 12.{If I write const befour * then contant will be constant..}
    // //*a = 20;
    // cout<<*a<<endl;
    // delete a;
    // int b = 5;
    // a = &b; // pointer a points to the address of b variable
    // cout<<*a<<endl;

    // *************************************************************

    // 3. Constant Pointer , but Non-Constant data
    // int *const a = new int(2);
    // cout<<*a<<endl;
    // *a = 20;
    // cout<<*a<<endl;
    // int b = 50;
    // a = &b; // nahi chalega , Constant pointer hai...

    //**********************************************************************

    // 4.Constant pointer , constant data
    //  const int *const a = new int(2);
    //  cout<<*a<<endl;
    //  *a = 20;     // this Expresion will not work..
    //  cout<<*a<<endl;

    return 0;
}
#include <iostream>
using namespace std;
// Function overloading
class Vector
{
    int x, y;

public:
    Vector(int x, int y): x(x), y(y) {}

    void operator+(const Vector &src  ){ // + overloading
    //  this would point to v1
    //  src would be ref to v2
        this->x+=src.x;
        this->y+=src.y;
    }

    void operator-(const Vector &src ){ // - overloading
    //  this would point to v1
    //  src would be ref to v2
        this->x-=src.x;
        this->y-=src.y;
    }

    void operator++(){ // ++ overloading
    //  this would point to v1
    //  src would be ref to v2
        this->x++;
        this->y++;
    }
      
    void operator--(){ // -- overloading
    //  this would point to v1
    //  src would be ref to v2
        this->x--;
        this->y--;
    }  

    void display()
    {
        cout << "x: " << x << " "
             << "y: " << y << endl;
    }
};
int main()
{
    Vector v1(2, 3);
    Vector v2(4, 5);
    Vector v3(6, 7);

    cout<<"Befor op overloading"<<endl;
    v1.display();
    v2.display();
     //--v1;
    // ++v1;
    // v1+v2;
    // v1+v3;
    // v1 - v2; for - overloading
    // v2 + v1; for + overloading
    cout<<"after op overloading"<<endl;
    v1.display();
    v2.display();

    //  addtion answe should be stroed in v1

    return 0;
}
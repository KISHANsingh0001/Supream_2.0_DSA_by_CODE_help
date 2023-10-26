#include <iostream>
#include<string>
using namespace std;

class Bird
{
public:
    int age, weight;
    int nol;
    string color;

    // Bird(int age, int weight, int nol, string color)
    // {
    //     // parametrized constructor called
    //     this->age = age;
    //     this->weight = weight;
    //     this->nol = nol;
    //     this->color = color;
    // }

    void eat()
    {
        cout << "Bird is eating" << endl;
    }

    void fly()
    {
        cout << "Bird is flying" << endl;
    }
};
// 1) yadi base class ka public data yadi child class main private inherit karte hai to 
//    child class main vo data private ho jata hai..
class Sparrow:private Bird
{
public:
    Sparrow(int age, int weight, int nol, string color)
    {
        // parametrized constructor called
        this->age = age;
        this->weight = weight;
        this->nol = nol;
        this->color = color;
    }
    // makeing geters 
    int get_age(){
        return age;
    }
    int get_weight(){
        return weight;
    }
    int get_nol(){
        return nol;
    }
    string get_color(){
        return color;
    }

    void grassing()
    {
        cout << "Sparrow is grssing" << endl;
    }
};

class Peigon : public Bird
{
public:
    void gutering()
    {
        cout << "Peigon is gutering" << endl;
    }
};

class Parrot : public Bird
{
public:
    void speaking()
    {
        cout << "Parrot is speaking" << endl;
    }
};
int main()
{
    Sparrow s(2, 200, 2, "black");
    cout<<s.get_nol();
    

    // Peigon p;
    // p.eat();

    Bird b;
    // cout<<b.age<<endl;
    // cout<<b.nol<<endl;

    // Parrot f;
    // f.speaking();
   
    // Bird b(1,300,2,"green");

    // cout<<b.color<<endl;
    // cout<<b.age<<" year"<<endl;
    
    // Peigon p;
    // p.gutering();
    return 0;
}
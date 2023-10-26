// This is a Diamond Problem
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    void walk()
    {
        cout << "walking..." << endl;
    }
};
class Teacher : virtual public Person // Virtual says to compiler ki sun tu na walk ki diffrent copy mat bana jab walk maga jaye to runtime per hi 
//                                       dono walk ko resolve karke dono class ko walk ki same copy dena...
{
public:
    void teach()
    {
        cout << "Teaching.." << endl;
    }
};

class Researcher : virtual public Person
{
public:
    void research()
    {
        cout << "Researching.." << endl;
    }
};
// Multiple Ingeritence
class Professor : public Teacher, public Researcher
{
public:
    void bore()
    {
        cout << "boreing..." << endl;
    }
};
int main()
{
    Professor p; // there is two walk() first one Teacher vala walk and second one is Researcher vala walk()
    // compiler samjh nahi pa rha  hai ki Teacher vala walk() lu ya Researcher vala walk()....this is the problem
//     p.walk(); // this will give error

    //  Solution 1.- scope resolution
    p.Teacher::walk();    // it means - p sun tu Teacher class ke walk ka use kar le..
    p.Researcher::walk(); // p sun tu Researcher class ke walk ka use kar le..

    // Solution 2.- using virtual keyword
    p.walk();

    return 0;
}
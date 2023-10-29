#include<iostream>
using namespace std;
// vitual teminology-: hum yaha baad main decide kar rahe hai ki kon sa sound call hoga(late binding)
// ye decition runtime main hoga ki hamara animal pointer kis ka object ko point kar raha hai....
class Animal
{
  public:
    virtual void sound(){
        cout<<"Animal makeing sound"<<endl;
    }

    virtual ~Animal()
    {
        cout<<"perent Class dtor called"<<endl;
       
    }
};
class Dog : public Animal{
    public:
    void sound() override
    {  
        cout<<"dog barking"<<endl;
    }

    virtual ~Dog()
    {
        cout<<"dog dtor called"<<endl;
    }
};
class Cat : public Animal
{
   void sound() override
    { 
        cout<<"Cat is Meowing"<<endl;
    }
    virtual ~Cat()
    {
        cout<<"cat dtor called"<<endl;
    }

};
void sound(Animal *animal){
    animal->sound();  // this line is polymorphic
    // animal->sound is behaving as per required object allocated at runtime

}
int main()
{
    Animal *animal = new Cat();
    sound(animal);

    animal = new Dog();
    sound(animal);

    delete animal;
   
    return 0;
}
#include <iostream>
using namespace std;
class Humen
{
public:
   virtual void work()
    {
        cout << "Humen is eating..." << endl;
    }
};
class Engineer : public Humen
{
    void work() override
    {
        cout << "Engineer is writeing the code.." << endl;
    }
};
class Teacher : public Humen
{
    void work() override
    {
        cout << "Teacher is teaching the students...." << endl;
    }
};
void work(Humen *humen){
    humen->work();
}
int main()
{
    Humen *humen = new Engineer();
    work(humen);
    humen = new Teacher();
    work(humen);
    return 0;
}
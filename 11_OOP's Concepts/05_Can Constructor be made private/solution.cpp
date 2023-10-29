// Can ctor be made Private ??? 
// Yes It can be made private.but we can't initialize the object of Box class if you are not using friend class

#include<iostream>
using namespace std;
class Box{
    int width;
    Box(int _w): width(_w){}; // INIT list is private 

    public:

   // Box(int _w): width(_w){}; // INIT list

    int getWidth()const
    {
        return width;
    }

    void setWidth(int _val){
        width = _val;
    }
    friend class BoxFectory; // eska matlab hai ki box class ka object sirf BoxFectory name ki class hi bana sakti hai


};
class BoxFectory{
      int count;

      public:
      Box getABox(int _w){
        ++count;
        return Box(_w);
      }

};
int main()
{
    // Box b(5);
    // cout<<b.getWidth()<<endl; 
    //  ctor ko private banane ka ek ye bhi requirment ho sakti hai ki aap chahte ho ko koi 
    //  Class Box ka object aasani se na bana paye.. per hum chahte hai ki aap box ko ek box 
    // fectory class ke through banao....
    
    BoxFectory bfect;
    Box b = bfect.getABox(10);
    cout<< b.getWidth()<<endl;
    return 0;
}
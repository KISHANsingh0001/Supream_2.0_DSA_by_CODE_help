// Interview related quesion 
//                                      Implimentation of two Stack using a dynamic array.......
#include<iostream>
using namespace std;
class Stack{
    public: // data members
   int *arr;
   int size;
   int top1;
   int top2;
  
   Stack(int size){ // paramitrized constructor
    this->arr = new int[size];
    this->size = size;
    this->top1 = -1;
    this->top2 = size;
   }
// member functions
void push1(int data){
    if(top2 - top1 == 1){
        cout<<"STACK IS OVERFLOWING"<<endl;
    }
    else{
        top1++;
        arr[top1] = data;
    }
}
void push2(int data){
    if(top2 - top1 == 1){
        cout<<"STACK IS OVERFLOWING"<<endl;
    }
    else{
        top2--;
        arr[top2] = data;
    }
}
void pop1(){
    if(top1 == -1){
        cout<<"UNDERFLOW"<<endl;
    }
    else{
        arr[top1] = 0;
        top1--;
    }
}
void pop2(){
    if(top2 == size){
        cout<<"UNDERFLOW"<<endl;
    }
    else{
        arr[top2] = 0;
        top2++;
    }
}
void print(){
   // cout<<endl;
    for(int i = 0 ; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
};
int main()
{
    Stack st(10);
    st.push1(10);
    st.push1(20);
    st.push1(30);
    st.push1(40);
    st.push1(50);
    st.push2(60);
    st.push2(70);
    st.push2(80);
    st.push2(90);
    st.push2(100);
    st.push1(10);
    st.print();
    return 0;
}
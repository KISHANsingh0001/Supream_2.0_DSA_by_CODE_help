#include <iostream>
#include<stack>
using namespace std;

int main() {

  //creation
  stack<int> st;

  //insertion
  st.push(10);
  st.push(20);
  st.push(30);

  //size check
  cout << "Size of stack is: " << st.size() << endl;

  //remove 
  st.pop(); 

  //check empty
  if(st.empty()) {
    cout << "Stack is empty" << endl;
  }
  else {
    cout << "stack is non empty" << endl;
  }


  //top element
  cout << st.top() << endl;


  return 0;
}
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> findStockSpans(vector<int> price) {
    int n = price.size();
    stack<pair<int , int>>st;
       vector<int>ans;
       for(int i = 0 ; i<n ;i++)
       {
          int span = 1;
          while(!st.empty() && st.top().first <= price[i]){
           span += st.top().second;
           st.pop();
           }
       st.push({price[i] , span});
       ans.push_back(span);
       }
       return ans;
}
int main()
{
    vector<int>price = {100,80,60,70,60,75,85,95};
    vector<int>span = findStockSpans(price);
     cout<<"Stcok span is printing: "<<endl;
    for(auto i:span){
        cout<<i<<" ";
    }
    return 0;
}
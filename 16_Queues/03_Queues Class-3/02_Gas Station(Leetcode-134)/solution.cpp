
#include <iostream>
#include<vector>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0;
    int balance = 0;
    int start = 0; // car start index se drive karna start karegi
    // har ek index ko check karege ki vo ans starting index hai ya nahi
    for (int i = 0; i < gas.size(); i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }
    // car circule complete kar chuki hai
    if (balance - deficit >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}
int main()
{
  vector<int> gas = {1,2,3,4,5};
  vector<int> cost = {3,4,5,1,2};
  cout<<canCompleteCircuit(gas , cost);
    return 0;
}
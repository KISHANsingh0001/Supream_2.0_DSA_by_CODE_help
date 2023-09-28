// Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine 
// that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees. Mirko‟s machine 
// works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and 
// cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts 
// that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises 
// his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while
//  Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

// Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade 
// as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M 
// metres of wood
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossibleAns(vector<long long int>& trees , long long int& m , long long int& mid){
    long long int woodCollected = 0;
    for (long long int  i = 0; i < trees.size(); i++)
    {
        if(trees[i] >= mid){
            woodCollected += trees[i] - mid;
        }
    }
    return woodCollected >= m; // if this condition is true so this function will return true other wise false;
    
}
long long int maxSawbladeHight(vector<long long int>& trees , long long int& m ){
    long long int s = 0 , e = *max_element(trees.begin() , trees.end()); // this function finds the maximum number in this array
    long long int ans = 0;
    while (s <= e)
    {
        long long int mid = s+(e-s)/2;
        if(isPossibleAns(trees , m , mid)){
           ans = mid;
           s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    long long int n , m ;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    cout<<"Enter the required wood in meters : "<<endl;
    cin>>m;
    vector<long long int> trees;
    cout<<"Enter the array elements "<<endl;
    while(n--){
        long long int hight_wood;
        cin>>hight_wood;
       trees.push_back(hight_wood);
    }
    long long int ans = maxSawbladeHight(trees , m);

    cout<<"SAW BLADE HIGHT IS : "<<ans;
    return 0;
}
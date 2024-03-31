// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

// Input: piles = [5,3,4,5]
// Output: true

#include <iostream>
#include <vector>
using namespace std;
bool stoneGame(vector<int> &piles)
{
    // there will be at least one way by which Alice will win.
    // that means , we should return true.
    // bcz problem is asking is there an way that Alice can win
    return true;
}
int main()
{
    vector<int> piles = {5, 3, 4, 5};
    if(stoneGame(piles)){
        cout<<"Alice has been won "<<endl;
    }
    else{
        cout<<"Bob has been won "<<endl;
    }

    return 0;
}
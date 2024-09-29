// 1) Single Sorce Shortest Path in directed weighted graph using DFS
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <limits.h>
#include <vector>
#include <set>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight, int direction)
    {
        if (direction == 1)
        {
            adj[u].push_back({v, weight});
        }
        else
        {
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
    }

    void findTopoOrdering(int src, stack<int> &topo, unordered_map<int, bool> &visted)
    {
        visted[src] = true;
        for (auto nbr : adj[src])
        {
            int nbrNode = nbr.first;
            if (!visted[nbrNode])
            {
                findTopoOrdering(nbrNode, topo, visted);
            }
        }

        topo.push(src);
    }

    void shortestPathDFS(stack<int> &topo, int n)
    {
        vector<int> dist(n, INT_MAX);

        // initally , maintain src
        int src = topo.top();
        dist[src] = 0;

        // update nbr distance for this src node

        for (auto &nbr : adj[src])
        {
            int nbrNode = nbr.first;
            int nbrDist = nbr.second;

            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }
        // apply the same above concept for all the remaining node in the topo ordering
        while (!topo.empty())
        {
            int src = topo.top();
            topo.pop();

            for (auto &nbr : adj[src])
            {
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if (dist[src] + nbrDist < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }

        // ab mera distance array ekdam tyaar hai
        cout << "printing the distence array " << endl;
        for (auto &i : dist)
        {
            cout << i << " ";
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << ": {  ";
            for (pair<int, int> p : i.second)
            {
                cout << "{" << p.first << ", " << p.second << "}, ";
            }
            cout << "}" << endl;
        }
    }

    void dijkstraShortestPath(int n, int src, int dist)
    {
        vector<int> dis(n + 1, INT_MAX);

        set<pair<int, int>> st;
        // initial state
        st.insert({0, src});
        dist[src] = 0;
        
        // distance updation logic
        while(!st.empty()){
            auto topEle = st.begin();
            pair<int,int> topPair = *topEle;

            int topDist = topPair.first;
            int topNode = topPair.second;
            // remove top node from the set
            st.erase(st.begin());

            // update distence of nbr 
            for(auto &nbrPair : adj[topNode]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if(topDist + nbrDist < dist[nbrNode]){
                    // found a new shorter distence
                    // now update: 
                    // set ki entry
                    auto previousEntry = st.find({dis[nbrNode] , nbrNode});
                    if(previousEntry != st.end()){
                        st.erase(previousEntry);
                    }

                    // dist ka array
                    dist[nbrNode] = topDist + nbrDist ;
                    st.insert({dist[nbrNode] , nbrNode});
                }
            }   
        }

    }
};

int main()
{
    Graph g;
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(0, 2, 3, 1);
    // g.addEdge(2, 1, 2, 1);
    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 3, 5, 1);
    // g.addEdge(2, 4, 6, 1);
    // g.addEdge(4, 3, 1, 1);

    g.addEdge(1,6,14,0);
	g.addEdge(1,3,9,0);
	g.addEdge(1,2,7,0);
	g.addEdge(2,3,10,0);
	g.addEdge(2,4,15,0);
	g.addEdge(3,4,11,0);
	g.addEdge(6,3,2,0);
	g.addEdge(6,5,9,0);
	g.addEdge(5,4,6,0);
    int n = 5;
    int src = 0;
    stack<int> topo;
    unordered_map<int, bool> visted;
    g.findTopoOrdering(src, topo, visted);
    // cout<<"Printing topo ordering"<<endl;
    // while (!topo.empty())
    // {
    //     cout<<topo.top()<<endl;
    //     topo.pop();

    g.shortestPathDFS(topo, n);
    return 0;
}

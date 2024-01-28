//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool solve(int src,unordered_map<int,bool>& visited,vector<int> adj[]) {
        queue<int> q;
      
      unordered_map<int,int> parent;
      //intiial state
      //int src = 0;
      q.push(src);
      visited[src] = true;
      parent[src] = -1; 

      while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto nbr: adj[frontNode]) {
           if(nbr == parent[frontNode]) {
                continue;
            }
          if(!visited[nbr]) {
            q.push(nbr);
            visited[nbr] = true;
            parent[nbr] = frontNode;
          }
          else if(visited[nbr] == true) {
            //cycle present 
            // cout << "nbr: " << nbr << endl;
            // cout << "frontNode: " << frontNode << endl;
            // cout << "parent[nbr]: " << parent[nbr] << endl;
            return true;
          }
        }
      }
      //cycle not present
      return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int,bool> visited;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                bool ans = solve(i, visited,adj);
                if(ans == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
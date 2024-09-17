class Solution {
  public:
    bool checkCycle(int src,unordered_map<int,bool>& vis, int parent,vector<int> adj[]) {
        vis[src] = true;
        
        for(auto nbr: adj[src]) {
            if(nbr == parent) {
                continue;
            }
            if(!vis[nbr]) {
                bool ans = checkCycle(nbr, vis, src, adj);
                if(ans == true) {
                    return true;
                }
            }
            else if(vis[nbr]==1 ) {
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool> vis;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                int parent = -1;
                bool isCyclic = checkCycle(i, vis, parent,adj);
                if(isCyclic == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
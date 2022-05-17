// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool cycDfs(int node, vector<int>& vis, vector<int>& dirvis,vector<int> adj[]){
        vis[node] = 1;
        dirvis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(cycDfs(it,vis,dirvis,adj))
                    return true;
            }
            else if(vis[it] == 1 and dirvis[it] == 1){
                return true;
            }
        }
        dirvis[node] = 0;
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0),dirvis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycDfs(i,vis,dirvis,adj))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
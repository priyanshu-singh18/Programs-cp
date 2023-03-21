//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void topoSort(int node , vector<pair<int,int>> adj[] , stack<int>& sop , vector<int>& vis){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first;
            
            if(!vis[v]){
                topoSort(v , adj , sop , vis);
            }
        }
        sop.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        
        vector<int> dist(N,1e9),vis(N,0);
        stack<int> sop;
        
        for(int i=0;i<N;i++){
            if(!vis[i]){
                
                topoSort(i,adj,sop,vis);
            }
        }
        
        
        dist[0] = 0;
        
        while(!sop.empty()){
            int node = sop.top();
            // cout<<"Node"<<node;
            sop.pop();
            
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt  < dist[v]){
                    dist[v] = wt + dist[node];
                    
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
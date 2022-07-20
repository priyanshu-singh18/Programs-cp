class Solution {
public:
    
    void solve(int node , int n , vector<int> vis,vector<int> v, vector<vector<int>>& graph, vector<vector<int>>& ans){
        
        
        vis[node] = 1;
        
        for(auto it : graph[node]){
            if(!vis[it]){
                v.push_back(it);
                solve(it,n,vis,v,graph,ans);
                v.pop_back();
            }
        }
        if(node == n-1){
            
            ans.push_back(v);
        }
        vis[node] = 0;
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans ;
        vector<int> vis(n,0);
        solve(0,n,vis,{0},graph,ans);
        return ans;
    }
};
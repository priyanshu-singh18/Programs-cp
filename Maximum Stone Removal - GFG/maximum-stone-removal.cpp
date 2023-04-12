//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int findPar(int x , vector<int>& parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findPar(parent[x] , parent);
    }
    
    void unionn(int x , int y , vector<int>& rank ,  vector<int>& parent){
        x = findPar(x,parent);
        y = findPar(y,parent);
        
        if(rank[x] > rank[y]){
            parent[y] = x;
            rank[x]++;
        }
        else if(rank[y] > rank[x]){
            parent[x] = y;
            rank[y]++;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
    
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        vector<int> parent(20001) , rank(20001,0);
        
        for(int i=0;i<20001;i++){
            parent[i] = i;
        }
        
        for(auto it : stones){
            unionn(it[0],it[1]+10000, rank,parent);
        }
        
        set<int> sop;
        
        for(auto it : stones){
            int u = findPar(it[0] , parent);
            sop.insert(u);
        }
        
        return n - sop.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends
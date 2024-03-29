// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string> ans;
    string s = "DLRU";
    vector<pair<int,int>> moves = {{1,0},{0,-1},{0,1},{-1,0}};
    
    void solve(int x , int y , vector<vector<int>>& vis, vector<vector<int>>& m, int n, string temp){
        if(x==n-1 and y==n-1){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<4;i++){
            int nx = x + moves[i].first;
            int ny = y + moves[i].second;
            
            if(nx>=n or ny>=n or nx<0 or ny<0 or vis[nx][ny] or m[nx][ny]==0)
                continue;
            
            temp.push_back(s[i]);
            vis[nx][ny] = 1;
            solve(nx,ny,vis,m,n,temp);
            temp.pop_back();
            vis[nx][ny] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n,vector<int>(n,0));
        string temp = "";
        vis[0][0] = 1;
        if(m[0][0]==1)
            solve(0,0,vis,m,n,temp);
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
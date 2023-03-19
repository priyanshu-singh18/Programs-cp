//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
          // code here
        int row = mat.size();
        int col = mat[0].size();
        
        
        queue<pair<int,int>> qop;
        int cnt1=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] == 1 ){
                    if(i==0 or j==0 or j==col-1 or i == row-1){
                        qop.push({i,j});
                        mat[i][j] = 2;
                    }
                    cnt1++;
                }    
            }
        }
        
        vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!qop.empty()){
            int x = qop.front().first;
            int y = qop.front().second;
            qop.pop();
            
            for(auto move : moves){
                int x1 = x + move.first;
                int y1 = y + move.second;
                
                if(x1>=0 and y1>=0 and x1<=row-1 and y1<col and mat[x1][y1]==1){
                    mat[x1][y1] = 2;
                    qop.push({x1,y1});
                }
            }
            
        }
        int cnt2=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] == 2){
                    cnt2++;
                }
            }
        }
        // cout<<cnt1<<"  "<<cnt2;
        return cnt1-cnt2;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        
        
        queue<pair<int,int>> qop;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] == 'O' and (i==0 or j==0 or j==col-1 or i == row-1) ){
                    qop.push({i,j});
                    mat[i][j] = 'F';
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
                
                if(x1>=0 and y1>=0 and x1<=row-1 and y1<col and mat[x1][y1]=='O'){
                    mat[x1][y1] = 'F';
                    qop.push({x1,y1});
                }
            }
            
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
                else if(mat[i][j] == 'F'){
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
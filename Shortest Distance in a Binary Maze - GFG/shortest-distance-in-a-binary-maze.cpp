//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> qop;
        vector<vector<int>> dist(row , vector<int>(col , 1e9));
        
        dist[source.first][source.second] = 0;
        qop.push({source.first , source.second});
        
        vector<pair<int,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!qop.empty()){
            int x = qop.front().first;
            int y = qop.front().second;
            qop.pop();
            
            for(auto move : moves){
                int x1 = x + move.first;
                int y1 = y + move.second;
                
                if(x1>=0 and y1>=0 and y1<col and x1<row and grid[x1][y1] ==1){
                    if(dist[x1][y1] > 1 + dist[x][y]){
                        dist[x1][y1] = 1 + dist[x][y];
                    }
                    grid[x1][y1] = 2;
                    qop.push({x1,y1});
                }
            }
            
            
        }
        if(dist[destination.first][destination.second] == 1e9){
            return -1;
        }
        return dist[destination.first][destination.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
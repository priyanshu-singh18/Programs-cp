//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row = grid.size();
	    int col = grid[0].size();
	    
	    vector<vector<int>> dist(row, vector<int> (col , INT_MAX));
	    
	    queue<pair<int,int>> qop;
	    
	    for(int i=0;i<row;i++){
	        for(int j=0;j<col;j++){
	            if(grid[i][j] == 1){
	                dist[i][j] = 0;
	                qop.push({i,j});
	            }
	        }
	    }
	    
	    vector<pair<int,int>> moves = {{1,0}, {0,1} , {-1,0} , {0,-1}}; 
	    
	    while(!qop.empty()){
	        int n = qop.size();
	        
	        while(n--){
	            int x = qop.front().first;
	            int y = qop.front().second;
	            qop.pop();
	            
	            for(auto move : moves){
	                int x1 = x + move.first;
	                int y1 = y + move.second;
	                
	                if(x1>=0 and x1<row and y1>=0 and y1<col and grid[x1][y1] == 0){
                        dist[x1][y1] = min(dist[x1][y1] , 1 + dist[x][y]);
	                    grid[x1][y1] = 2;
	                    qop.push({x1 , y1});
	                }
	            }
	        }
	    }
	    
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
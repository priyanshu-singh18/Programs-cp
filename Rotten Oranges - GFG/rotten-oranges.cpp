//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> qop;
        int fresh = 0 , seconds = 0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2){
                    qop.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        vector<pair<int,int>> moves = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        
        while(!qop.empty() and fresh>0){
            int n = qop.size();
            seconds++;
            while(n--){
                int x = qop.front().first;
                int y = qop.front().second;
                qop.pop();
                
                for(auto it : moves){
                    int x1 = x + it.first;
                    int y1 = y + it.second;
                    
                    if(x1<row && y1<col && x1>=0 && y1>=0 &&  grid[x1][y1] == 1){
                        fresh--;
                        qop.push({x1, y1});
                        grid[x1][y1] = 2;
                    }
                }
                
            }
        }
        if(fresh > 0){
            return -1;
        }
        return seconds;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
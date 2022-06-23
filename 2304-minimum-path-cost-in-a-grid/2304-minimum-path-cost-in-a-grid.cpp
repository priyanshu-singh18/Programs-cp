class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans = INT_MAX;
        int row = grid.size(), col = grid[0].size();
        
        int cost[col];
        
        vector<vector<int>> dp(row,vector<int> (col,INT_MAX));
        
        for(int j=0;j<col;j++){
            for(int i=0;i<col;i++){
                dp[1][j] = min(dp[1][j] , grid[0][i] + moveCost[grid[0][i]][j]);  
                
            }
            
        }
      
        for(int i=2;i<row;i++){
            
            for(int j =0;j<col;j++){
                 for(int k=0;k<col;k++){
                     dp[i][j] = min(dp[i][j] ,dp[i-1][k]+ grid[i-1][k] + moveCost[grid[i-1][k]][j]);
                 }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j = 0;j<col;j++)
                cout<<dp[i][j]<<"           ";
            cout<<endl;
        }
        
        
        int mini = INT_MAX;
        
        for(int i =0;i<col;i++)
            mini = min(mini, dp[row-1][i] + grid[row-1][i]);
        
        return mini;
    }
};
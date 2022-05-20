class Solution {
public:
    int ans = 0,n,m; 
    
    
    int dfs(int x, int y, vector<vector<int>>& dp,vector<vector<int>>& grid,int last){
        
        if(x<0 or y<0 or x>=m or y>=n or grid[x][y]<=last)
            return 0;
        
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
    
       return dp[x][y] = 1 + max( {dfs(x+1,y,dp,grid,grid[x][y]),
        dfs(x,y+1,dp,grid,grid[x][y]),
        dfs(x-1,y,dp,grid,grid[x][y]),
        dfs(x,y-1,dp,grid,grid[x][y])} );
        
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dfs(i,j,dp,matrix,-1)) ;
            }
        }
        return ans;
    }
};
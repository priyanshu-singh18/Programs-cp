class Solution {
public:
    
    void dfs(int x , int y ,int m,int n, vector<vector<int>>& grid, int& ar){
        if(x>=m or y>=n or x<0 or y<0 or grid[x][y]!=1)
            return;
        
        ar++;
        grid[x][y] = 0;
        dfs(x+1,y,m,n,grid,ar);
        dfs(x-1,y,m,n,grid,ar);
        dfs(x,y+1,m,n,grid,ar);
        dfs(x,y-1,m,n,grid,ar);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int ar=0;
                    dfs(i,j,m,n,grid,ar);
                    ans = max(ar,ans);
                }
            }
        }
        return ans;
    }
};
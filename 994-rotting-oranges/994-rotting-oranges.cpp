class Solution {
public:
    
    vector<pair<int,int>> moves = {{0,1},{1,0},{-1,0},{0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int cnt = 0;
        queue<pair<int,int>> qop;
        // vector<vector<int>> vis(row, vector<int> (col,0));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                if(grid[i][j]==2){
                    qop.push({i,j});
                    
                }
                else if(grid[i][j] == 1)
                    cnt++;
        }
        
        if(!cnt)
            return 0;
        
        int time=0;
        
        while(!qop.empty()){
            int n = qop.size();
            
            while(n--){
                int p = qop.front().first;
                int q = qop.front().second;
                qop.pop();
                
                for(auto move : moves){
                    int x = move.first + p;
                    int y = move.second + q;
                    
                    if( x<0 or y<0 or x>row-1 or y>col-1 or grid[x][y]!=1)
                        continue;
                    
                    grid[x][y] = 2;
                    qop.push({x,y});
                }
                
            }
            time++;
        }
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j] == 1)
                    return -1;
        return time-1;
    }
};
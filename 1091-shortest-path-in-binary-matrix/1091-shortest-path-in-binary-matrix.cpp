class Solution {
public:
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        
        queue<pair<int,int>> qop;
        qop.push({0,0});
        int step = 0;
        
        while(!qop.empty()){
            int size = qop.size();
            step++;
            while(size--){
                int x = qop.front().first;
                int y = qop.front().second;
                qop.pop();
            
                 
                if(x == n-1 and y == n-1)
                    return step;
                    
                
                for(auto it : moves){
                    int x1 = x + it.first;
                    int y1 = y + it.second;
                
                
                    if(x1<0 or y1<0 or x1>n-1 or y1>n-1 or grid[x1][y1]!=0)
                        continue;
                
                    grid[x1][y1] = 1;
                    qop.push({x1,y1});
                
                }
            }
            
    
        }
        return -1;
    
    
   
    }
};
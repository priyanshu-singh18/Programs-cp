class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        if ( n == 1){
            return 1;
        }

        vector<pair<int,int>> directions = {
            {0,1} , {0,-1} , {1, 0} , {-1 , 0},
            {1, 1} , {1, -1} , {-1 , 1} , {-1, -1}
        };

        queue<tuple<int,int,int>>  q;

        q.push({0,0,1});

        grid[0][0] = 1;

        while(!q.empty()){
            auto [row, col ,pathLen] = q.front();

            q.pop();

            for (auto [dr  , dc] : directions){
                int newRow = row + dr;
                int newCol = col + dc;

                if(newRow < 0 || newRow>=n || newCol < 0 || newCol>= n){
                    continue;
                }

                if(grid[newRow][newCol] != 0){
                    continue;
                }

                if(newRow == n-1 && newCol == n-1){
                    return pathLen + 1;
                }

                grid[newRow][newCol] = 1;
                q.push({newRow , newCol , pathLen + 1});
            }

        }
        return -1 ;
    }
};
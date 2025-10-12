class Solution {
public:
    vector<pair<int,int>> directions= {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void bfsIsland(int i , int j , vector<vector<char>>& grid , vector<vector<int>>& vis){
        vis[i][j] = 1;
        queue<pair<int,int>> qop;
        qop.push({i,j});

        while(!qop.empty()){
            auto it = qop.front();
            qop.pop();

            int x1 = it.first;
            int y1 = it.second;

            for (auto dir : directions){
                int x2 = dir.first + x1;
                int y2 = dir.second + y1;

                if(x2< 0 or y2 < 0 or x2 >= grid.size() or y2>=grid[0].size() ) continue;
                if(vis[x2][y2]) continue;
                if(grid[x2][y2] != '1') continue;

                vis[x2][y2] = 1;
                qop.push({x2,y2});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size() , col = grid[0].size() , res = 0;
        vector<vector<int>> vis(row , vector<int> ( col , 0));

        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfsIsland(i, j , grid , vis);
                    res+=1;
                }
            }
        }

        return res;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() , n =mat[0].size();

        queue<pair<int,int>> qop;

        for(int i = 0 ; i<m ; i++){
            for(int j=0 ; j<n; j++){
                if(mat[i][j] == 0){
                    qop.emplace(i,j);
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }

        vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!qop.empty()){
            auto [x,y] = qop.front();
            qop.pop();

            for(auto move : moves){
                int x1 = x + move.first;
                int y1 = y + move.second;

                if(x1<0 || y1<0 || x1==m || y1 ==n || mat[x1][y1] != -1 ) continue;

                mat[x1][y1] = mat[x][y]+1;
                qop.emplace(x1,y1);
            }
        }

        return mat;

    }
};
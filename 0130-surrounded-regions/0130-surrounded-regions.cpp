class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> qop;
        int m = board.size() , n = board[0].size();

        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j++){
                if((i==0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O' ){
                    board[i][j] = 'Z'; 
                    qop.emplace(i,j);
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

                if(x1 < 0 || y1<0 || x1==m || y1==n || board[x1][y1]!='O') continue;

                board[x1][y1] = 'Z';
                qop.emplace(x1,y1);
            }
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j]=='Z'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};
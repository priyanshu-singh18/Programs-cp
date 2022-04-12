class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        auto op = [&] (int x,int y){
            
        };
        
        vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
                int cnt1=0,cnt0=0;
                
                for(auto x : moves){
                    int p = i + x.first;
                    int q = j + x.second;
                    if(p<0 or q<0 or p>row-1 or q>col-1 )
                        continue;
                    // or board[p][q]==2 or board[p][q]==3
                    if(board[p][q]==1 or board[p][q]==3)
                        cnt1++;
                    if(board[p][q]==0 or board[p][q]==2)
                        cnt0++;
                    
                }
                
                if(board[i][j]==0 and cnt1==3)
                    board[i][j]=2;
                else if(board[i][j]==1 and cnt1<2)
                    board[i][j]=3;
                else if(board[i][j]==1 and cnt1>3)
                    board[i][j]=3;
                
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==2)
                    board[i][j]=1;
                else if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
        
    }
};
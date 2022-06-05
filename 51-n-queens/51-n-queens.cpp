class Solution {
public:
    vector<vector<string>> ans;
    
    void solve(int col, vector<string>& temp, int n, vector<int>& upDiag, vector<int>& leftRow, vector<int>& downDiag){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && downDiag[col+row]==0 && upDiag[n - 1 + col - row]==0){                
                temp[row][col] = 'Q';
                upDiag[n-1 +col-row] = 1;
                leftRow[row]=1;
                downDiag[row+col] = 1;
                solve(col+1,temp,n,upDiag,leftRow,downDiag);
                upDiag[n-1 +col-row] = 0;
                leftRow[row]=0;
                downDiag[row+col] = 0;
                temp[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<int> upDiag(2*n-1,0),downDiag(2*n-1,0), leftRow(n,0);
        vector<string> temp(n,string(n,'.'));
        solve(0,temp,n,upDiag,leftRow,downDiag);
        return ans;
    }
};
class Solution {
public:
    
    int ans = 0;
    
    void solve(int col, int n, vector<int>& left, vector<int>& upDiag, vector<int>& downDiag){
        if(n == col){
            ans++;
            return;
        }
        
        for(int row=0;row<n;row++){
            if(left[row]==0 and upDiag[n-1 + col - row]==0 and downDiag[row + col]==0){
                left[row] = 1;
                upDiag[n-1 + col - row] = 1;
                downDiag[row + col] = 1;
                
                solve(col+1,n,left,upDiag,downDiag);
                
                left[row] = 0;
                upDiag[n-1 + col - row] = 0;
                downDiag[row + col] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<int> left(n,0),upDiag(2*n-1,0),downDiag(2*n-1,0);
        
        solve(0,n,left,upDiag,downDiag);
        return ans;
    }
};
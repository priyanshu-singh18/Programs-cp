class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int h1 = 0,h2 = n-1,v1=0,v2=n-1,val=1;
        vector<vector<int>> mat(n,vector<int>(n));
        while(h1<=h2 and v1<=v2){
            for(int i=h1;i<=h2;i++){
                mat[v1][i]=val++;
            }
            
            for(int j=v1+1;j<=v2;j++){
                mat[j][h2] = val++;
            }
            
            for(int i=h2-1;i>=h1;i--){
                mat[v2][i] = val++;
            }
            
            for(int j= v2-1;j>=v1+1;j--){
                mat[j][h1] = val++;
            }
            
            h1++,v1++,v2--,h2--;
        }
        return mat;
    }
};
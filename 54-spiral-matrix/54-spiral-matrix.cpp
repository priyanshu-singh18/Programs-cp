class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> res;
        
        int h1 =0,h2=n-1,v1=0,v2=m-1;
        
        while(h1<=h2 and v1<=v2){
            for(int i=h1;i<=h2;i++){
                res.push_back(matrix[v1][i]);
            }
            for(int j=v1+1;j<=v2;j++)
                res.push_back(matrix[j][h2]);
            if(v1!=v2){
                
            
            for(int i=h2-1;i>=h1 ;i--)
                res.push_back(matrix[v2][i]);
            
                }
            if(h1!=h2){
            for(int j=v2-1;j>=v1+1;j--)
                res.push_back(matrix[j][h1]);
            }
            
            h1++,v1++,h2--,v2--;
        }
        
        return res;
    }
};
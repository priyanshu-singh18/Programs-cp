class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int i = 0, j = col-1;
        
        while(i>=0 and j>=0 and j<=col-1 and i<=row-1){
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j] > target){
                j--;
            }
            else
                i++;
        }
        return false;
    }
};
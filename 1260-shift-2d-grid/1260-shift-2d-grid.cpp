class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        auto move=[&](vector<vector<int>> &a)
        {
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                temp.push_back(a[i][m-1]);
                int cur=a[i][0];
                for(int j=1;j<m;j++)
                {
                    int temp=a[i][j];
                    a[i][j]=cur;
                    cur=temp;
                }
            }
            for(int i=1;i<n;i++)
            {
                a[i][0]=temp[i-1];
            }
            a[0][0]=temp[n-1];
            return a;
        };
        for(int i=0;i<k;i++)
        {
            grid=move(grid);
        }
        return grid;
    }
};
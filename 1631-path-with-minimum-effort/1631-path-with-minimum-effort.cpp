class Solution {
public:
    vector<vector<int>> vis;
    bool valid(int x,int y,int n,int m)
    {
        if(x<n&&y<m&&x>=0&&y>=0&&!vis[x][y])
        {
            return true;
        }
        return false;
    }
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    void dfs(int x,int y,int n,int m,vector<vector<int>> &adj,int diff)
    {
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny,n,m)&&abs(adj[nx][ny]-adj[x][y])<=diff)
            {
                dfs(nx,ny,n,m,adj,diff);
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo=0,hi=1e6;
        int ans=-1;
        int n=heights.size();
        int m=heights[0].size();
        auto ok=[&](int diff)
        {
            //dfs
            vis=vector<vector<int>> (n,vector<int> (m));
            dfs(0,0,n,m,heights,diff);
            return vis[n-1][m-1];
        };
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(ok(mid))
            {
                hi=mid-1;
                ans=mid;
            }
            else
            {
                lo=mid+1;
            }
        }
        return ans;
    }
};
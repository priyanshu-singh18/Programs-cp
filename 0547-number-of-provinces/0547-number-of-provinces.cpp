class Solution {
public:

    void bfs(int node , vector<int>& visited , vector<vector<int>>& adj){
        queue<int> qop;
        visited[node] = 1;
        qop.push(node);

        while(!qop.empty()){
            int x = qop.front();
            qop.pop();

            for(int neighbour : adj[x]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    qop.push(neighbour);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        int ans =0 ;
        vector<int> visited(n);

        for(int i=0 ; i<n ;i++){
            for(int j=0 ;j<n ;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,visited , adj);
                ans+=1;
            }
        }

        return ans;
    }
};
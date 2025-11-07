class Solution {
public:

    vector<vector<pair<int,int>>> buildAdjacencyList(int V , vector<vector<int>>& times){
        vector<vector<pair<int ,int>>> adj(V+1);
        for(auto time : times){
            adj[time[0]].push_back({time[1] , time[2]});
        }
        return adj;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj = buildAdjacencyList(n , times);

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            pair<int,int> it = pq.top();
            int node = it.second;
            pq.pop();

            for(auto x : adj[node]){
                int x_dist = x.second;
                int x_node = x.first;

                if(dist[x_node] > x_dist + dist[node]){
                    dist[x_node] = x_dist + dist[node];
                    pq.push({dist[x_node] , x_node});
                }
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(dist[i] , ans);
        }
        return ans;
    }
};
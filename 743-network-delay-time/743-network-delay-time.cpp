class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<pair<int,int>> graph[n+1];
        
        for(int i = 0 ; i<m ; i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            int p_dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            for(auto it : graph[prev]){
                int nextDist = it.second;
                int next = it.first;
                
                if(dist[next] > nextDist + p_dist){
                    dist[next]= nextDist + p_dist;
                    pq.push({dist[next],next});
                }
            }
        }
        bool flag = true;
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                flag=false;
                
                }
            maxi = max(dist[i],maxi);       
        }
        if(!flag) return -1;
        return maxi;
    }
};
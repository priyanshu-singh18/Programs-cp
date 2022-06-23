class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        vector<int> indeg(n,0);
        vector<int> topo;
        //kahns algorithm
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        
        queue<int> qop;
        
        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                qop.push(i);
        
        while(!qop.empty()){
            int node = qop.front();
            qop.pop();
            
            topo.push_back(node);
            
            for(auto it : adj[node]){
                if(indeg[it]>0){
                    indeg[it]--;
                    
                    if(indeg[it]==0)
                        qop.push(it);
                }
                else
                    continue;
            }
            
        }
        
        if(topo.size()==n)
            return true;
        
        return false;
        
    }
};
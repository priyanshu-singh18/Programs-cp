class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> adj[numCourses];
        vector<int> inDegree(numCourses,0);
        
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);    
            inDegree[pre[i][0]]++;
        }
        
        queue<int> qop;
        vector<int> topo;
        
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0)
                qop.push(i);
        }
        
        while(!qop.empty()){
            int node = qop.front();
            qop.pop();
            
            topo.push_back(node);
            
            for(auto it : adj[node]){
                if(inDegree[it]>=1){
                    inDegree[it]--;
                    if(inDegree[it]==0)
                        qop.push(it);
                }
            }
        }
        if(topo.size( ) == numCourses)
            return true;
        return false;
        
    }
};
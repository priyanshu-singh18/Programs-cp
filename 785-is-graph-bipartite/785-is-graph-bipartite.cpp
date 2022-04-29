class Solution {
public:
    bool bfsop(int node, vector<int>& color, vector<vector<int>> graph){
        color[node]=1;
        queue<int> qop;
        qop.push(node);
        
        while(!qop.empty()){
            int nop = qop.front();
            qop.pop();
            
            for(auto it : graph[nop]){
                if(color[it]==-1){
                    color[it] = 1 - color[nop];
                    qop.push(it);
                }
                else if(color[it] == color[nop]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!bfsop(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};
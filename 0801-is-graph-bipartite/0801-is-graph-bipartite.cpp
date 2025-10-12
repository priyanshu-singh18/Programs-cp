class Solution {
public:
    // bfs
    bool solveBfs(int i , vector<int>& color, vector<vector<int>>& graph){
        color[i] = 1; 

        queue<int> qop;
        qop.push(i);

        while(!qop.empty()){
            int curr_v = qop.front();
            int curr_col = color[curr_v];
            qop.pop();

            for(auto ed : graph[curr_v]){
                int col_to_fill = curr_col == 1 ? 2 : 1;

                if (color[ed] != -1 and color[ed] == curr_col ){
                    return false;
                } else if(color[ed] == -1) {
                color[ed] = col_to_fill;
                qop.push(ed);
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);

        for(int i = 0 ; i < V ; i++){
            if(color[i]== -1){
                color[i] = 1;
                if(!solveBfs(i , color , graph)){
                    return false;
                }
            }
        }
        return true;
    }
};
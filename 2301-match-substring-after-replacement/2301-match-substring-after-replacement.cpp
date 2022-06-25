class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char,unordered_set<char>> umap;
        
        for(auto it : mappings)
            umap[it[0]].insert(it[1]);
        
        int k = sub.length();
        
        for(int i=0;i<=s.length()-k;i++){
            bool check = true;
            
            for(int j=0;j<k;j++){
                char op1 = s[i+j],op2 = sub[j];
                
                if(op1==op2 or umap[op2].find(op1) != umap[op2].end())
                    continue;
                else{
                    check = false;
                    break;
                }
            }
            if(check)
                return true;
        }
        return false;
    }
};
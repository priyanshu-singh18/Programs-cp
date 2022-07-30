class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> umap;
        vector<string> res;
        
        for(auto word : words2){
            unordered_map<char,int> temp;
            for(auto c : word){
                temp[c]++;
                if(umap.find(c) == umap.end() or temp[c] > umap[c])
                    umap[c] = temp[c];
            }
        }
        
        for(auto word : words1){
            unordered_map<char,int> temp;
            for(auto c : word){
                temp[c]++;
            }
            int flag = 0;
            unordered_map<char,int> :: iterator it;
            for(it = umap.begin() ; it!=umap.end() ; it++){
                if(temp.find(it->first) == temp.end() or temp[it->first] < it->second){
                    flag = 1; 
                    break;
                }
                
            }
            if(!flag)
                res.push_back(word);
        }
        return res;
    }
};
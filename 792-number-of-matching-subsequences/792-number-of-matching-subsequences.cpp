class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char , vector<int>> umap;
        
        for(int i=0;i<s.size();i++)
            umap[s[i]].push_back(i);
        
        int ans = 0;
        
        for(auto word : words){
            bool found = true;
            for(int i=0 , prev =-1;i<word.size() && found;i++){
                auto& v  = umap[word[i]];
                auto it = upper_bound(v.begin(),v.end() , prev);
                if(it == v.end())
                    found = false;
                else
                    prev = *it;
            }
            ans+=found;
        }
        return ans;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sm(26),tm(26);
        
        for(auto x : s)
            sm[x - 'a']++;
        
        for(auto x : t)
            tm[x - 'a']++;
        
        return sm==tm;
    }
};
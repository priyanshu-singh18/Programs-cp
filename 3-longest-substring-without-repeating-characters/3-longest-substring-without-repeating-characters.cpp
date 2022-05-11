class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> umap;
        
        int l=0,r=0,ans=0;
        
        while(r<s.size()){
            umap[s[r]]++;
            
            while(umap[s[r]] > 1){
                umap[s[l]]--;
                l++;   
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
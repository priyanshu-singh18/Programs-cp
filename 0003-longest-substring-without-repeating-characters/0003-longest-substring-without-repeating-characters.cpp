class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0 , j = 0 ;
        unordered_map<char , int> umap;

        while(j<n){
            umap[s[j]]++;

            while(i<j && umap[s[j]] > 1){
                umap[s[i]]--;
                i++;
            }

            ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};
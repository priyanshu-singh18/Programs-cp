class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        
        sort(words.begin(),words.end(),[] (string a , string b){
            return a.length() < b.length();
        });
        
        int ans = 0;
        
        for(auto s : words){
            for(int i=0;i<s.length();i++){
                string temp = s.substr(0,i) + s.substr(i+1);
                
                dp[s] = max(dp[s], dp.find(temp)==dp.end() ? 1 : dp[temp] + 1);
            }
            ans = max(ans,dp[s]);
        }
        return ans;
    }
};
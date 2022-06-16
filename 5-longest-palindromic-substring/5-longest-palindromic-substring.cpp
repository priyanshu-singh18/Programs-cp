class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        
        if(n==1)
            return s;
        
        for(int g = 0; g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)
                    dp[i][j] = true;
                else if(g==1)
                    dp[i][j] = s[i] == s[j];
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]==true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
            }
        }
        
        string ans = "";
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j] == true and j-i+1> maxi){
                    maxi = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};
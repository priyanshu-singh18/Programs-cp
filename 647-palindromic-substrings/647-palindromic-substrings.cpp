class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(),ans=0;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0)
                    dp[i][j]=1,ans++;
                else if(g==1){
                    if(s[i]==s[j])
                        dp[i][j] = 1,ans++;
                }                                  
                else{   
                    if(s[i]==s[j] && dp[i+1][j-1]==1)
                        dp[i][j] =1,ans++;
                }
                
            }
        }
        return ans;
    }
};
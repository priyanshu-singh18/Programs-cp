class Solution {
public:
    int dp[605][101][101];
    int solve(vector<string>& strs , int m0 , int n1 , int n){
    if(n<0){
        return 0;
    }

    if (dp[n][m0][n1] != -1) return dp[n][m0][n1];

    int c0=0 , c1=0;
    string rel_str = strs[n];

    for(int i = 0 ; i < rel_str.length() ; i++){
        if(rel_str[i] == '1'){
            c1+=1;
            continue;
        }
        c0+=1;
    }
    int pick = 0;

    if(m0 >= c0 && n1 >= c1){
        pick = 1 + solve(strs , m0 - c0, n1 - c1 , n-1 );
    }
    int not_pick = solve(strs , m0 , n1 , n-1 );
    return dp[n][m0][n1] = max(pick , not_pick);
    }

    int findMaxForm(vector<string>& strs, int m, int n ) {
        memset(dp,-1,sizeof(dp));
        int s = strs.size();
        int ans = solve(strs , m , n , s-1);
        return ans;
    }
};
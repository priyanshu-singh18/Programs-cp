class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        target = abs(target);
        if(n==1){
            if(abs(nums[0]) == abs(target))
                return true;
            return false;
        }
        
        for(auto x : nums)
            sum+=x;
        
         if(sum<target||(sum+target)%2!=0)
            return 0;
        
        int k = (sum + target)/2;
        int dp[n+1][k+1];
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=k;i++)
            dp[0][i] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j<nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][k];
    }
};
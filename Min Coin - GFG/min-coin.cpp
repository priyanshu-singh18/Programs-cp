// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	   // // Code here
	   // //can take any value greater than amount like:amount+1,amount+2,10001 or INT_MAX	
	   //vector<int> dp(amount+1,10001);
	   ////now enter the value for dp[0]=0
	   //dp[0]=0;
	   //// it is based on three steps,
	   //// 1. pick the current coin=>dp[j-nums[i]]+1, here +1 for picking this coin
	   //// 2. dont pick the current coin=>dp[i] value remains same
	   //// 3. minimum of both of them  
	   //for(int i=0;i<nums.size();i++)
	   //{
	   //    for(int j=1;j<=amount;j++)
	   //    {
	   //        if(nums[i]<=j)
	   //         dp[j]=min(dp[j],dp[j-nums[i]]+1);
	   //    }
	   //}
	   //if(dp[amount]>amount)
	   // return -1;
	   //return dp[amount];
	   
	   int n = nums.size();
	   vector<vector<int>> dp(n+1,vector<int>(amount+1));
	   
	   for(int i=0;i<amount+1;i++){
	       dp[0][i] = 1e8;
	   }
	   for(int i=1;i<=n;i++){
	       dp[i][0] = 0;
	   }
	   
	   //for(int i=1;i<amount+1;i++){
	   //    if(amount%nums[0]==0)
	   //     dp[1][i] = amount/nums[0];
	   //    else
	   //     dp[1][i] = 1e8;
	   //}
	   
	   for(int i=1;i<=n;i++){
	       for(int j=1;j<=amount;j++){
	           if(nums[i-1] <=j){
	               dp[i][j] = min((1 + dp[i][j-nums[i-1]] ), dp[i-1][j]);
	           }
	           else
	            dp[i][j] = dp[i-1][j];
	       }
	   }
	   if(dp[n][amount] > amount)
	        return -1;
	   return dp[n][amount];     
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
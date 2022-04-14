class Solution {
public:
//     int maxProfit(vector<int>& arr) {
//         int mini = arr[0];
//         int pist = 0,n = arr.size();
//         int larr[n];
//         larr[0] = 0;
//         for(int i=1;i<n;i++){
//             mini = min(mini,arr[i]);
//             pist = arr[i] - mini;
            
//             larr[i] = max(larr[i-1],pist );
//         }
        
//         int maxi = arr[n-1];
//         int pibt = 0,rarr[n];
//         rarr[n-1] = 0;
        
//         for(int i=n-2;i>=0;i--){
//             maxi = max(arr[i],maxi);
//             pibt = maxi - arr[i];
            
//             rarr[i] = max(rarr[i+1],pibt);
//         }
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             ans = max(ans,larr[i]+rarr[i]);
//         }
//         return ans;
//     }
    int maxProfit(vector<int>& ar) {
        
        if(ar.size() == 0)
            return 0;
        
        vector<int>dp(3,0);
        vector<int>mn(3,ar[0]);
        
        for(int i=1;i<ar.size();i++){
            for(int k=1;k<=2;k++){
                mn[k] = min(mn[k],ar[i] - dp[k-1]);
                dp[k] = max(dp[k],ar[i] - mn[k]);
            }
        }
        return dp[2];
    }
};
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
        int n=ar.size();
        int mini=ar[0];
        multiset<int> s;
        for(int i=1;i<n;i++)
        {
            s.insert(ar[i]);
        }
        int ans=0;
        vector<int> suf(n);
        int maxi=ar[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(maxi,ar[i]);
            suf[i]=max(suf[i+1],maxi-ar[i]);
        }
        for(int i=1;i<n;i++)
        {
            int second=0;
            if(i+1<n)
            {
                second=suf[i+1];
            }
            mini=min(mini,ar[i]);
            // cout<<mini<<' '<<ar[i]<<' '<<second<<'\n'; 
            ans=max(ans,ar[i]-mini+second);
        }
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum1=0,sum2=0,ans=0,flag=0;
        
        for(auto y : nums)
            sum1+=y;
        
        if(sum1<x)
            return -1;
        
        
        int i=0;
        sum1-=x;
        
        for(int j=0;j<nums.size();j++){
            sum2+=nums[j];
            
            while(i<nums.size() and sum2>sum1){
                sum2-=nums[i++];
            }
            
            if(sum1==sum2){
                ans = max(ans, j-i+1);
                flag=1;
            }
        }
        if(!flag)
            return -1;
        return nums.size()-ans;
    }
};
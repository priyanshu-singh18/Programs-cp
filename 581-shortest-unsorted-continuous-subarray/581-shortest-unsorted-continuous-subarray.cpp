class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start=-1,end=n,currmin = INT_MAX,currmax = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(currmin > nums[i]) currmin = nums[i];
            if(nums[i] > currmin) start=i;
        }
        
        for(int i=0;i<=n-1;i++){
            if(currmax < nums[i]) currmax = nums[i];
            if(nums[i] < currmax) end = i;
        }
        if(start==-1)
            return 0;
        return end-start+1;
    }
};
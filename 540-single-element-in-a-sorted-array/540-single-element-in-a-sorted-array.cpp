class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        int low = 0, high = nums.size()-1,mid;
        
        while(low<high){
            mid = low + (high-low)/2;
            
            
            if((mid)%2==0){
                 if( nums[mid]==nums[mid+1])
                     low = mid + 1;
                else
                    high = mid;
            }
            else if((mid)%2 ==1){
                if(nums[mid]!=nums[mid-1])
                    high = mid;
                else
                    low = mid + 1;
            }
        }
        return nums[low];
    }
};
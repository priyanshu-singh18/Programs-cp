class Solution {
public:
    
    int binary(int low, int high, vector<int>& nums, int target){
        int mid;
        while(low<=high){
            mid = low + (high-low)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]> target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0,piv, high = n-1, mid;
        
        while(low<=high){
            mid = low + (high-low)/2;
            
            if(nums[mid]<=nums[(mid+1)%n] and nums[mid]<=nums[(mid-1+n)%n]){
                piv = mid;
                break;
            }
            else if(nums[high] > nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
    
        
       return max(binary(0,piv-1,nums,target),binary(piv,n-1,nums,target)); 
    }
};
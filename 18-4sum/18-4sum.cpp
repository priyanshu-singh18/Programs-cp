class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int need = target - nums[i] - nums[j];
                
                int left = j+1, right = n-1;
                
                while(left<right){
                    int sum = nums[left] + nums[right];
                    if(need < sum){
                       right--;
                    }
                    else if(need > sum ){
                       left++;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int fop = nums[left],bop = nums[right];
                        
                        while(left<right and nums[left] == fop)
                            left++;
                        while(left<right and nums[right] == bop)
                            right--;
                    }
                }
                while(j+1<n and nums[j]==nums[j+1])
                    j++;
            }
            while(i+1<n and nums[i+1]==nums[i])
                i++;
        }
        return ans;
    }
};
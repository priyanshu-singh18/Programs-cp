class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(int i, int target, vector<int>& nums, vector<int>& temp){
        
         if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(i==nums.size() or target<0)
            return;
       
        
        temp.push_back(nums[i]);
        solve(i+1,target - nums[i] , nums, temp);
        
        temp.pop_back();
        
        while(i+1<nums.size() and nums[i+1]==nums[i])
            i++;
        solve(i+1,target,nums,temp);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,target,nums,temp);
        return ans;
    }
};
class Solution {
public:
    
    vector<vector<int>> ans;
    
    
    void solve(int i, vector<int>& temp, int k, int n, vector<int>& nums, int& sum){
        if(temp.size()>=k || i>8){
            if(temp.size()==k and sum == n)
                ans.push_back(temp);
            return;
        }
        sum+=nums[i];
        temp.push_back(nums[i]);
        solve(i+1,temp,k,n,nums,sum);
        
        sum-=nums[i];
        temp.pop_back();
        solve(i+1,temp,k,n,nums,sum);
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        int sum = 0;
        solve(0,temp,k,n,nums,sum);    
        return ans;
    }
};
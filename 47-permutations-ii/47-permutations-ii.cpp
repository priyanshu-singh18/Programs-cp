class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, vector<int>& temp, vector<bool>& vis){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(vis[i])
                continue;
            if(i>0 and nums[i-1]==nums[i] and !vis[i-1])
                continue;
            
            temp.push_back(nums[i]);
            vis[i] = true;
            
            solve(nums,temp,vis);
            
            temp.pop_back();
            vis[i] = false;
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        vector<bool> vis(n,false);
        solve(nums,temp,vis);
        return ans;
    }
};
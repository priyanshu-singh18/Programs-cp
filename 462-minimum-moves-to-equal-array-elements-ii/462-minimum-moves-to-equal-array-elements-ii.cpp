class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans= 0;
        for(int i=0;i<nums.size()/2;i++){
            ans+=nums[nums.size()-1 - i] - nums[i];
        }
        return ans;
    }
};
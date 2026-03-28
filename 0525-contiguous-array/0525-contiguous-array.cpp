class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0,sum=0;

        unordered_map<int,int> seen;
        seen[0] = -1;

        for(int i = 0 ; i< n ; i++){
            sum += nums[i] ? 1 : -1 ;
            if(seen.count(sum)) ans = max(ans , i - seen[sum]);
            else seen[sum] = i;
        }
        return ans;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                if(i==nums.size()-1)
                    ans = max(ans, count);
            }
            else{
                ans = max(ans, count);
                count = 0;
            }
        }
        return ans;
    }
};
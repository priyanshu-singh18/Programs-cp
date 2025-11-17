class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_idx = -1;
        int n = nums.size();

        for(int i=0 ; i <n ;i ++){
            if(nums[i] == 1){
                if(last_idx != -1){
                    if(i-last_idx - 1 < k){
                        return false;
                    }
                }
                last_idx = i;
            }
        }
        return true;
    }
};
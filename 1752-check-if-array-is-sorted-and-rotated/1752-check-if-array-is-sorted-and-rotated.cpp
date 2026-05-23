class Solution {
public:
    bool check(vector<int>& nums) {
        // lets find out pivot point and then check if they are sorted ? O(n + logn) = O(n)
        int max_decrement = 1;
        int n = nums.size();

        for(int i=1;i<n;i++){
            if (nums[i] < nums[i-1]){
                max_decrement--;
            }
        }
        if (nums[n-1] > nums[0]){
            max_decrement--;
        }
        return max_decrement>=0;
    }
};
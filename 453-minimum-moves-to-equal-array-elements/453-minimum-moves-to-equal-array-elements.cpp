class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long int sum=0;
        int mini = INT_MAX;
        
        for(auto x : nums){
            mini = min(mini, x);
            sum+=x;
        }
        
        
        return sum - mini* nums.size();
        
    }
};
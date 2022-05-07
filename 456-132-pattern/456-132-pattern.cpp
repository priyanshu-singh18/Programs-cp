class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> sop;
        int s1, s3=INT_MIN;
        bool ans = false;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] < s3)
                return true;
            
            while(!sop.empty() and nums[i]> sop.top()){
                s3 = sop.top();
                sop.pop();
            }           
            sop.push(nums[i]);
        }
        return ans;
    }
};
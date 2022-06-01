class Solution {
public:
   vector<int> runningSum(vector<int>& nums) {
       int temp=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            v.push_back(temp);
        }
        return v;
    }
};
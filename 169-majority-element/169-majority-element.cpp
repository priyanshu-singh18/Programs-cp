class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1,maxindex=0;
        
        for(int i =0;i<nums.size();i++){
            if(nums[i]==nums[maxindex]){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    maxindex=i;
                    cnt=1;
                }
            }
        }
        return nums[maxindex];
    }
};
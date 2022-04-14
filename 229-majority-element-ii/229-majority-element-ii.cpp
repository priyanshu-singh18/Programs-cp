class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int max1=-1,max2=-1,cnt1=0,cnt2=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max1){
                cnt1++;
            }
            else if(nums[i]==max2){
                cnt2++;
            }
            else if(cnt1==0){
                max1 = nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                max2=nums[i];
                cnt2=1;
            }
            else
                cnt1--,cnt2--;
        }
        int c1=0,c2=0;
        for(auto x : nums){
            if(x==max1)
                c1++;
            else if(x==max2)
                c2++;
        }
        vector<int> ans;
        if(nums.size()/3 < c1) ans.push_back(max1);
        if(nums.size()/3 < c2) ans.push_back(max2);
        return ans;
    }
};
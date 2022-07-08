class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0= 0 , c1 = 0 , c2 = 0;
        
        for(auto x : nums){
            if(x == 0)
                c0++;
            else if(x==1)
                c1++;
            else
                c2++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(c0){
                nums[i] = 0;
                c0--;
            }
            else if(c1){
                nums[i] = 1;
                c1--;
            }
            else{
                nums[i] = 2;
                c2--;
            }
        }
    }
};
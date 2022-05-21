class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            int need = -nums[i];
            int low = i+1,high = n-1;
            
            if(need<0)
                break;
            while(low<high){
                int sum = nums[low] +nums[high];
                if(sum > need){
                    high--;
                }
                else if(sum<need){
                    low++;
                }
                else{
                    vector<int> op = {nums[i],nums[low],nums[high]};
                    ans.push_back(op);
                    
                    while(low<high and nums[low] == op[1])
                        low++;
                    while(low<high and nums[high] == op[2])
                        high--;
                    
                }
            }
            while(i+1<n and nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};
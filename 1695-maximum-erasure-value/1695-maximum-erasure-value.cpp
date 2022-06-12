class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> umap;
        int sum = 0 ,i=0,j=0,ans=0;
        
        while(j<nums.size()){
            sum+=nums[j];
            umap[nums[j]]++;
            
            while(umap[nums[j]]>1){
                sum-=nums[i];
                umap[nums[i]]--;
                i++;
            }
            j++;
            ans = max(ans,sum);
        }
        return ans;
    }
};
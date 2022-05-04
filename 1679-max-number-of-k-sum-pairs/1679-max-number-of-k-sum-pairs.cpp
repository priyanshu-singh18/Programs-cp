class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        
        for(auto x : nums)
            umap[x]++;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(umap[nums[i]]>0){
                int need = k - nums[i];
                if(umap.find(need)!=umap.end()){
                    if(umap[need]>0){
                        if(nums[i] == need){
                            if(umap[nums[i]]>=2){
                                cnt++;
                                umap[nums[i]] -=2;
                            }
                        }
                        else{
                            umap[need]--;
                            umap[nums[i]]--;
                            cnt++;
                        }
                        
                    }
                }
            }
        }
        return cnt;
    }
};
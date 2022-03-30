typedef long long int ll; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<ll,ll> umap;
        vector<int> v;
        for (int i = 0 ; i < nums.size() ; i++) {

            ll value = target-nums[i];

            if(umap.find(value)!=umap.end()){
                v.push_back(umap[value]);
                v.push_back(i);
                return v;
            }
            umap.insert(make_pair(nums[i],i));
        }
        return v;
    }
};
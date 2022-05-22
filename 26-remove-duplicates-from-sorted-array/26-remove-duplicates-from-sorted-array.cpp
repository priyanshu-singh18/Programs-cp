class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        
        for(auto x : nums)
            s.insert(x);
        
        copy(s.begin(),s.end(),nums.begin());
        return s.size();
    }
};
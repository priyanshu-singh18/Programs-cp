class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//         set<int> s;
        
//         for(auto x : nums)
//             s.insert(x);
        
//         copy(s.begin(),s.end(),nums.begin());
//         return s.size();
        
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[i] !=nums[j]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};
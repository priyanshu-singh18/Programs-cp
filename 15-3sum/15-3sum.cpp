class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        
        for (int i=0;i<n;i++){
            int temp = nums[i]*-1;
            int front = i+1,back = n-1;
            
            if(temp<0)
                break;
            
            while(front<back){
                int sum = nums[front] + nums[back];
                
                if(sum<temp)
                    front++;
                else if(sum>temp)
                    back--;
                else{
                    vector<int> op = {nums[i],nums[front],nums[back]};
                    res.push_back(op);
                    
                    while(front<back and nums[front] == op[1])
                        front++;
                    while(front<back and nums[back] == op[2])
                        back--;
                }
                
            }
            while(i+1 < n and nums[i+1] == nums[i])
                i++;
            
        }
        return res;
        
    }
};
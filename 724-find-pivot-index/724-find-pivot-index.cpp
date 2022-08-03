class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // brute
//         for(int i=0;i<nums.size();i++){
//             int sum1=0,sum2=0;
            
//             for(int j=0;j<i;j++){
//                 sum1+=nums[j];
//             }
//             for(int j=i+1;j<nums.size();j++){
//                 sum2+=nums[j];
//             }
//             if(sum1 == sum2)
//                 return i;
//         }
//         return -1;
//         int n = nums.size();
//             vector<int> left(n,0), right(n,0);
        
//         for(int i=1;i<n;i++)
//             left[i] = nums[i-1] + left[i-1];
//         for(int i=n-2;i>=0;i--)
//             right[i] = nums[i+1] + right[i+1];
        
//         for(int i=0;i<n;i++){
//             if(left[i] == right[i])
//                 return i;
//         }
//         return -1;
        
        // o(1) space
        
        int leftSum = 0 , rightSum = accumulate(nums.begin(), nums.end(),0);
        
        for(int i=0;i<nums.size();i++){
            rightSum-=nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> window(k);
        int sum=0;

        for(int i = 0 ; i<k ; i++){
            window[i]=nums[i];
            sum+=nums[i];
        }
        cout<<sum;
        double max_avg = double(sum/(double)k);

        for(int i = k ; i < n ; i++){
            sum = sum + nums[i] - nums[i-k];

            max_avg = max(max_avg , double(sum/(double)k));
        }
        return max_avg;
    }
};
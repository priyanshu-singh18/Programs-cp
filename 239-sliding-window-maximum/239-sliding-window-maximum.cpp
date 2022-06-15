class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        
        
        deque<pair<int,int>> qop;
        
        for(int i=0;i<k;i++){
            while(!qop.empty() and nums[i]>qop.back().first){
                qop.pop_back();
            }
            qop.push_back({nums[i],i});
        }
        
        ans.push_back(qop.front().first);
        
        for(int i = k;i<n;i++){
            if(!qop.empty() and qop.front().second == i -k)
                qop.pop_front();
            
            while(!qop.empty() and nums[i]>qop.back().first){
                qop.pop_back();
            }
            qop.push_back({nums[i],i});
            ans.push_back(qop.front().first);
        }
        
        return ans;
    }
};
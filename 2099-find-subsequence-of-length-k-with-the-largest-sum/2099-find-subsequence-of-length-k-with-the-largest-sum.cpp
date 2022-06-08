class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size() > k)
                pq.pop();
            
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>              qop;
        
        while(!pq.empty()){
            qop.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        
        vector<int> ans;
        
        while(!qop.empty())
            ans.push_back(qop.top().second),qop.pop();
        
        return ans;
    }
};
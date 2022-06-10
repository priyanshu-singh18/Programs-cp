class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       stack<int> sop;
        unordered_map<int,int> umap;
        vector<int> ngr;
        
       for(int i=nums2.size()-1;i>=0;i--){
           if(sop.empty())
               ngr.push_back(-1);
           else if(!sop.empty() and sop.top() > nums2[i])
               ngr.push_back(sop.top());
           else if(!sop.empty() and sop.top() <= nums2[i]){
               while(!sop.empty() and sop.top() <=nums2[i]){
                   sop.pop();
               }
               if(sop.empty())
                   ngr.push_back(-1);
               else
                   ngr.push_back(sop.top());
           }
           sop.push(nums2[i]);
           umap[nums2[i]]=i;
       }
        
       reverse(ngr.begin(),ngr.end());
        vector<int> ans;
       for(int i=0;i<nums1.size();i++){
           ans.push_back(ngr[umap[nums1[i]]]);
       }
        return ans;
    }
};
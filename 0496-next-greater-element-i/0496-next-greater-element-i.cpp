class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n2 = nums2.size();
        unordered_map<int,int> umap;

        vector<int> next_greater(n2);

        for(int i = nums2.size() -1 ; i>=0 ; i--){
            if(!st.empty() && nums2[i] < st.top()){
                next_greater[i] = st.top();
            }
            else if(!st.empty() && nums2[i] >= st.top()){
                while(!st.empty() && st.top() <= nums2[i] ){
                    st.pop();
                }
                if(st.empty()){
                    next_greater[i] = -1;
                }
                else{
                    next_greater[i] = st.top();
                }
            }
            else{
                next_greater[i] = -1;
            }
            st.push(nums2[i]);
            umap[nums2[i]] = i;
        }

        vector<int> res(nums1.size());

        for(int i = 0 ; i < nums1.size();i++){
            res[i] = next_greater[umap[nums1[i]]];
        }
        return res;
    }
};
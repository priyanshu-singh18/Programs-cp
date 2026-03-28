class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;

        int n = temp.size();
        vector<int> res(n);

        for(int i = n-1 ; i>=0 ; i--){
            if(st.empty()){
                res[i] = 0;
            }
            else if(!st.empty() && st.top().first > temp[i]){
                res[i] = st.top().second - i;
            }
            else if(!st.empty() && st.top().first<=temp[i]){
                while(!st.empty() && st.top().first<=temp[i]){
                    st.pop();
                }
                if(st.empty()){
                    res[i] = 0;
                }
                else{
                   res[i] = st.top().second - i; 
                }
            }
            st.push({temp[i] , i});
        }
        return res;
    }
};
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int mini = INT_MAX,p;
        vector<int> idxs;
        
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i] == list2[j]){
                    if(mini > i+ j){
                        idxs.clear();
                        mini = i + j;
                        idxs.push_back(i);
                    }
                        
                    else if(mini == i + j)
                        idxs.push_back(i);
                        
                }
            }
        }
        for(auto x : idxs)
            ans.push_back(list1[x]);
        
        return ans;
    }
};
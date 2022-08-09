class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(), [](vector<int>& a , vector<int>& b){
           if(a[1] == b[1])
               return a[0]<b[0];
            return a[1]<b[1];
        });
        int res = INT_MIN;
        for(int j=0;j<pairs.size();j++){
            
            int ls = pairs[j][1],cnt =1;

            for(int i=j+1;i<pairs.size();i++){
                if(pairs[i][0]> ls){
                    ls = pairs[i][1];
                    cnt++;
                }
            }
            res = max(res , cnt);
        }
        for(auto x : pairs)
            cout<<x[0]<<"_"<<x[1]<<" ";
        return res;
    }
};
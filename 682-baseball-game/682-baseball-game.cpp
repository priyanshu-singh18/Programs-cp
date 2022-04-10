class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(auto str : ops){
            if(str!="C" and str!="D" and str!="+"){
                v.push_back(stoi(str));
            }
            else if(v.size()>0 and str=="C"){
                v.pop_back();
            }
            else if(str=="D"){
                int n = v.size();
                v.push_back(2*v[n-1]);
            }
            else {
                int n = v.size();
                v.push_back(v[n-1] + v[n-2]);
            }
        }
        int sum = 0;
        for(auto x : v)
            sum+=x;
        return sum;
    }
};
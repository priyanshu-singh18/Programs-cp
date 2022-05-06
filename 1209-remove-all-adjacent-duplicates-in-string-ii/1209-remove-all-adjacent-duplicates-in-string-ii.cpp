class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> sop;
        sop.push({'#',0});
        
        for(auto x : s){
            if(sop.top().first != x){
                sop.push({x,1});
            }
            else if(++sop.top().second == k){
                sop.pop();    
            }
        }
        string str="";
        while(sop.size()>1){
            str.append(sop.top().second,sop.top().first);
            sop.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
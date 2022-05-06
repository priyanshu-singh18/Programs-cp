class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sop;
        
        for(auto c : s){
            if(!sop.empty() and sop.top() == c){
                sop.pop();
            }
            else{
                sop.push(c);
            }
        }
        string str="";
        while(!sop.empty()){
            str+=sop.top();
            sop.pop();
        }
        
        reverse(str.begin(),str.end());
        return str;
    }
};
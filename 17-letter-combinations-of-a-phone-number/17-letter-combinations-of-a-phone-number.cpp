class Solution {
public:
    vector<string> letterCombinations(string digits) {
         const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
        
        int len = digits.size();
        if(len==0)
            return {};
        vector<string> ans;
        ans.push_back("");
        for(auto x : digits){
            vector<string> temp;
            for(auto y : pad[x-'0']){
                for(auto z : ans){
                    temp.push_back(z + y);
                }
            }
            ans.swap(temp);
        }
        return ans;
    }
};
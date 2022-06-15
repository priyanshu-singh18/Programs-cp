class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str;
        int len = INT_MAX;
        
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<len)
                str = strs[i],len = strs[i].size();
        }
        len = INT_MAX;
        for(int i=0;i<=strs.size()-1;i++){
            string temp = strs[i];
            int j=0;
            while(j<str.size() and temp[j] == str[j]){
            
                j++;
            }
            len = min(len,j);
        }
        
        return str.substr(0,len);
    }
};
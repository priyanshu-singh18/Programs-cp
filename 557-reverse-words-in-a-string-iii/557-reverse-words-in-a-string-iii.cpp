class Solution {
public:
    string reverseWords(string s) {
        int l = 0,i=0,j;
        
        while(l<s.size()){
            if(s[l] == ' ' or l == s.size()-1){
                if(s[l] == ' ')
                    j = l-1;
                else
                    j = l;
                while(i<j){
                    swap(s[i++],s[j--]);
                }
                i = l+1;
                l++;
            }
            else{
                l++;
            }
        
        }
        return s;
    }
};
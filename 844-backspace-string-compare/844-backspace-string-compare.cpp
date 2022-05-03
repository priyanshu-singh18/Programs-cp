class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str="",ttr="";
        int i = s.length()-1,j=t.length()-1,c1=0,c2=0;
        
        while(i>=0 or j>=0){
            
            if(i>=0 and s[i]=='#'){
                c1++;
                i--;
            }
            else{
                if(c1>0){
                    i--;
                    c1--;
                }
                else if(i>=0){
                    str+=s[i];
                    i--;
                }
            }
            
                if(j>=0 and t[j]=='#'){
                c2++;
                j--;
            }
            else{
                if(c2>0){
                    j--;
                    c2--;
                }
                else if(j>=0){
                    ttr+=t[j];
                    j--;
                }
            }
        }
        return str==ttr;
    }
};
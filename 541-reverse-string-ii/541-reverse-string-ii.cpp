class Solution {
public:
    string reverseStr(string s, int k) {
        
        for(int i=0;i<s.length();i=i+2*k){
            int x,y;
            x = i;
            y = i+k-1 > s.size()-1 ? s.size()-1 : i+k-1  ;
            
            while(x<y){
                swap(s[x++],s[y--]);
            }
            
        }
        return s;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0,n=s.length();
            
        while(j<n){
            
            if(s[j] != ' '){
                i = j;
                   while(j<n and s[j]!=' ')
                        j++;
                reverse(s.begin()+i,s.begin()+j);
            }
            else{
                int c = j;
                while(j<n and s[j]==' '){
                    s[j] = '#';
                    j++;                      
                }
                
            }
            
         
        }
        while(s[0]=='#')
            s.erase(0,1);
        while(s[s.length()-1] == '#')
            s.erase(s.length()-1,1);
        reverse(s.begin(),s.end());
        
        string temp="",ans="";
        
        for(int k=0;k<s.length();k++){
            if(s[k]=='#'){
                if(ans=="")
                    ans=temp;
                else if(temp!="")
                    ans = ans + " " + temp;
                temp="";
            }
            else if(s[k]!='#'){
                temp+=s[k];
            }
        }
        
        if(temp!=""){
             if(ans=="")
                ans=temp;
             else if(temp!="")
                ans = ans + " " + temp;
        }
        return ans;
        
        
    }
};
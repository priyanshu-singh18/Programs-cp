class Solution {
public:
    int compareVersion(string s1, string s2) {
        string temp1="",temp2="";
        int n1=s1.size(),n2=s2.size();
        int i=0,j=0;
        int c1,c2;
        
        while(i<n1 or j<n2){
            while(i<n1 and s1[i]!='.'){
                temp1+=s1[i];
                i++;
                
            }
            while(j<n2 and s2[j]!='.'){
                temp2+=s2[j];
                j++;
                
            }
            i++,j++;
            
            if(temp1!="")
                c1 = stoi(temp1);
            else
                c1=-1;
            if(temp2!="")
                c2 = stoi(temp2);
            else
                c2=-1;
            
            if(c1>c2 and c1!=0)
                return 1;
            else if(c2>c1 and c2!=0)
                return -1;
            
            temp1="",temp2="";
            
        }
        
        return 0;
    }
};
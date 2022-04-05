// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string s){
        // code here 
        int i=s.length()-2;
        
        while(i>=0 and int(s[i]) <= int(s[i+1])){
            i--;
        }
        if(i==-1)
            return "-1";
        else{
            if(i==0 and s[i+1]=='0')
                return "-1";
            int j = s.length()-1;
            while(s[i] <= s[j] and i<j){
                j--;
                
            }
            while(s[j] == s[j-1])
                j--;
            swap(s[j],s[i]);
        }
        return s;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends
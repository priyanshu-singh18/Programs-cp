//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> sop;
        for(auto x : s){
            if(sop.empty() || sop.top()!=x){
                sop.push(x);
            }
            else if(sop.top() == x){
                sop.pop();
            }
        }
        if(sop.empty())
            return "-1";
        string ans = "";
        while(!sop.empty()){
            char c = sop.top();
            sop.pop();
            ans = ans+c;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
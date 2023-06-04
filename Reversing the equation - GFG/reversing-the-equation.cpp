//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<char> op;
            stack<string> nums;
            string res = "";
            
            for(int i=0;i<s.length();){
                if(s[i]=='+' || s[i] == '-' || s[i] == '/' || s[i] == '*'){
                    op.push(s[i]);
                    i++;
                }
                else{
                    string num = "";
                    while(i < s.length() && isdigit(s[i])){
                        num+=s[i];
                        i++;
                    }
                    nums.push(num);
                }
            }
            // while(!nums.empty()){
            //     cout<<nums.top()<<" ";
            //     nums.pop();
            // }
            
            while(!nums.empty()){
                res += nums.top();
                nums.pop();
                
                if(!op.empty()){
                    res+=op.top();
                    op.pop();
                }
            }
            return res;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
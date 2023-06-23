//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        int i = 0;
        
        while(i<x.length()){
            int ch = x[i];
            if(ch=='{' || ch=='[' || ch=='('){
                st.push(ch);
            }
            else if(!st.empty() && ch==')' && st.top()=='('){
                st.pop();
            }
            else if(!st.empty() && ch=='}' && st.top()=='{'){
                st.pop();
            }
            else if(!st.empty() && ch==']' && st.top()=='['){
                st.pop();
            }
            else{
                return false;
            }
            
            i++;
            
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
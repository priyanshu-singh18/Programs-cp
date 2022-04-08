// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int a[],int n)
    {
        // code here
        unordered_map<int,int> m;
        stack<int> s;
        vector<int> ans;
    
        for(int i = 0; i < n; i++)
            m[a[i]]++;
    
        for(int i = n-1; i >= 0; i--) {
            
            while(!s.empty() && m[s.top()] <= m[a[i]]){
                s.pop();
            } 
    
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top());
    
            s.push(a[i]);
        }
    
        reverse(ans.begin(), ans.end());
    
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends
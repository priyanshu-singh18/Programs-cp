// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        // code here
        int len ;
        int pos = -1;
        int mini = INT_MAX;
        
        for(int i=0;i<n;i++){
            len = ar[i].size();
            
            if(len< mini){
                pos=i;
                mini = len;
            }
        }
        
        for(int i=0;i<mini;i++){
            char op = ar[pos][i];
            
            for(int j=0;j<n;j++){
                if(ar[j][i]!=op){
                    if(i==0)
                        return "-1";
                    return ar[pos].substr(0,i);    
                }
            }
        }
        
        return ar[pos].substr(0,mini);
    }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends
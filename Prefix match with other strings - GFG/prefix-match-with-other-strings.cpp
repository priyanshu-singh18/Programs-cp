//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        vector<string> v;
        
        if(str.length()<k){
            return 0;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(arr[i].length() >=k)
            v.push_back(arr[i].substr(0,k));
        }
        string check = str.substr(0,k);
        
        int res = 0 ; 
        
        for(auto it : v){
            if(it==check){
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
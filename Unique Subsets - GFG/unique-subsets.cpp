// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    
    void solve(int idx, vector<int>& temp, vector<int>& arr, vector<vector<int>>& ans){
        if(idx>=arr.size()){
            ans.push_back(temp);
            return;
        }
                
            temp.push_back(arr[idx]);
            solve(idx+1,temp,arr,ans);
            temp.pop_back();
            while(idx+1<arr.size() and arr[idx+1]==arr[idx] )
                idx++;
            solve(idx+1,temp,arr,ans);
        
    }
    
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,temp,arr,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void solve(int col,int n,vector<int>& temp,vector<vector<int>>& ans,
    vector<int>& left,
    vector<int>& downdiag, vector<int>& updiag){
          if(temp.size()==n){
              ans.push_back(temp);
              return;
          }
          
          for(int row=0;row<n;row++){
              if(left[row]==0 and downdiag[row+col]==0  and updiag[n-1 - row + col]==0){
                  temp.push_back(row+1);
                  left[row] = 1;
                  updiag[n-1 + col- row] = 1;
                  downdiag[col+row] = 1;
                  solve(col+1,n,temp,ans,left,downdiag,updiag);
                  temp.pop_back();
                  left[row] = 0;
                  updiag[n-1 + col- row] = 0;
                  downdiag[col+row] = 0;
              }
             
          }
          
    }


    vector<vector<int>> nQueen(int n) {
        // code here
       vector<int> left(n,0) , downdiag(2*n -1,0),updiag(2*n-1,0);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,n,temp,ans,left,downdiag,updiag);
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
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
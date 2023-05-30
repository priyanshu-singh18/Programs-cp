//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int u=0 , d=n-1 , l=0 , r=m-1,cnt =0, i =0 , j = 0;
        vector<int> ans;
        while(u<=d && l <=r){
            for(int i = l ; i<=r ;i++){
                ans.push_back(a[u][i]);
            }
            u++;
            
            for(int i = u ; i<=d ;i++){
                ans.push_back(a[i][r]);
            }
            r--;
            
            for(int i = r ; i>=l ;i--){
                ans.push_back(a[d][i]);
            }
            d--;
            
            for(int i = d ; i>=u ;i--){
                ans.push_back(a[i][l]);
            }
            l++;
        }

        return ans[k-1];
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends
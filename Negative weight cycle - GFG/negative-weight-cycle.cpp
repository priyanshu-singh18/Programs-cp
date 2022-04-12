// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	   vector<vector<pair<int,int>>> adj(n);
	   for(auto x:edges)
	   {
	        adj[x[0]].push_back({x[1],x[2]});   
	   }
	   vector<int> d(n,1e9);
	   bool is=false;
	   for(int i=0;i<n;i++)
	   {
	       bool change=false;
	       for(int j=0;j<n;j++)
	       {
	           for(auto x:adj[j])
               {
	                if(d[j]+x.second<d[x.first])
	                {
	                    d[x.first]=d[j]+x.second;
	                    change=true;
	                }
               }
	       }
	       if(change)
	       {
	           is=true;
	       }
	       else
	       {
                is=false;	           
	       }
	   }
	   return is;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
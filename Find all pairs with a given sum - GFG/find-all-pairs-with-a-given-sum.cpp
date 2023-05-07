//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    // void twosum(int arr[] , int len, int X , vector<pair<int,int>>& res){
    //     unordered_map<int,int> umap;
        
    //     for(int i=0;i<len;i++){
    //         int rem = X - arr[i];
            
    //         if(umap.find(rem) != umap.end()){
    //             res.push_back({arr[i] , rem });
    //         }
    //     }
    // }
    
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        vector<pair<int,int>> res;
        
        unordered_map<int,int> umap;
        
        for(int i=0;i<M;i++){
            umap[B[i]] = i;
        }
        
        for(int i=0;i<N;i++){
            int rem = X - A[i];
            
            if(umap.find(rem) != umap.end()){
                res.push_back({A[i] , rem });
            }
        }
        
        sort(res.begin() , res.end() , [] (pair<int,int>& a , pair<int,int>& b) -> bool{
            if(a.first > b.first){
                return false;
            }
            return true;
        });
        return res;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void sieve(int n, map<int,int> &umap){
        vector<int> primes(n+1 , true);
        
        for(int p=2;p<=n;p++){
            if(primes[p]){
                for(int i=p*p ; i <=n ; i+=p){
                    primes[i] = false;
                    
                }
            }
        }
        
        
        
        for(int i=2;i<=n;i++){
            if(primes[i]){
                umap[i] = true;
            }
        }
        
    }
  
    vector<int> leastPrimeFactor(int n) {
        // code here                                                                                                                                   
        map<int,int> umap;
        
        sieve(n , umap);
        
        vector<int> res(n+1,0);
        res[1] = 1;
        
        for(int i =2;i<=n;i++){
            if(umap.find(i) !=umap.end()){
                res[i] = i;
            }
            else{
                auto it = umap.begin();
                while(it!=umap.end()){
                    if(i % it->first == 0){
                        res[i] = it->first;
                        break;
                    }
                    it++;
                }
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends
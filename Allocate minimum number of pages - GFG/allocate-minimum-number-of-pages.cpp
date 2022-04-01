// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool helper(int A[], int N, int M, int mid){
        int simp = 0, studs = 1;
        
        for(int i=0;i<N;i++){
            simp += A[i];
            
            if(simp > mid){
                studs++;
                simp = A[i];
            }
            if(studs > M)
                return false;
        }
        return true ;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int sum = 0, maxi=0 , ans = -1;
        if(M>N)
        return -1;
        for(int i=0;i<N;i++){
            sum+=A[i];
            maxi = max(maxi,A[i]);
            
        }
        int low = maxi, high = sum,mid;
        
        while(low<=high){
            mid = low + (high-low)/2;
            
            if(helper(A,N,M,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
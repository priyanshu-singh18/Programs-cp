// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  bool  helper(int arr[],long long m,int k,int n){
        long painters=1;
        long time=0;
        for(int i=0;i<n;i++){
            if(time+arr[i]<=m){
                time+=arr[i];
            }else{
                painters++;
                if(painters>k || arr[i]>m){
                    return false;
                }
                time=arr[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long sum = 0;
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
            sum+=arr[i];
        }
        
        long long low = maxi, high = sum, mid,ans;
        
        while(low<=high){
            mid = low + (high-low)/2;
            int i = 0,c=1;
            
            int op = 0;
            // while(i<n){
            //     op+= arr[i];
            //     if(op>=mid){
            //         c++;
            //         op = 0;
            //     }
            //     i++;
            // }
            
            
            
            if(helper(arr,mid,k,n)){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
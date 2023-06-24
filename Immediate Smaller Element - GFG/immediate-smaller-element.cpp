//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	    int prev = 0;
	    for(int i = 0 ; i < n-1; i++){
	        if(i>0){
	            arr[i-1] = prev; 
	        }
	        if(arr[i] > arr[i+1]){
	            prev = arr[i+1];
	        }
	        else{
	            prev = -1;
	        }
	    }
	    arr[n-2] = prev;
	    arr[n-1] = -1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos , neg;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i] < 0){
	            neg.push_back(arr[i]);
	        }    
	        else{
	            pos.push_back(arr[i]);
	        }
	    }
	    int j=0,k=0,l=0;
	    for(int i=0;i<n;i++){
	        if((!l || k==neg.size()) && j < pos.size()){
	            arr[i] = pos[j++];
	            l=1;
	        }
	        else{
	            arr[i] = neg[k++];
	            l=0;
	        }
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
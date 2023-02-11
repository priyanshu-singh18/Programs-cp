//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<2*n;i++){
            int first = i<n ? n-i : i-n+1 ;
            int second = i<n ? 2 * i : 2 * (2*n - i -1); 
            for(int j=0;j<first ; j++){
                cout<<"*";
            }
            for(int j=0;j<second;j++){
                cout<<" ";
            }
            for(int j=0;j<first ; j++){
                cout<<"*";
            }
            cout<<endl;
        }
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends
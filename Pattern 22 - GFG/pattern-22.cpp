//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // code here
        int row = 2*n - 1;
        int col = 2*n - 1;
        
        for(int i=0;i<row;i++){
            int num = n;
            int count = i<n ? i : 2*n -i -2;
            while(count){
                cout<<num--<<" ";
                count--;
            }   
            count =  i<n ? col - 2*i :  2*(i+1) - col ;
            while(count>0){
                cout<<num<<" ";
                count--;
            }
            num++;
        count = i<n ? i : 2*n -i -2;
            while(count>0){
                cout<<num++<<" ";
                count--;
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends
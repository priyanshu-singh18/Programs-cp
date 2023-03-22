//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool isGood(int num, int D, int& sum){
        int last = num%10;
        
        if(num <=0){
            return true;
        }
        
        if(last == D){
            return false;
        }
        if(sum >= last){
            return false;
        }
        sum+=last;
        return isGood(num/10 , D , sum);
        
    }
  
  
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int> res;
        
        for(int i=L;i<=R;i++){
            int sum = i%10;
                        if(sum == D) continue;

            if(isGood(i/10 ,D , sum)){
                res.push_back(i);
                
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
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends
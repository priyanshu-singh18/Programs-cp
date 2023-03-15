//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long gcd(long long a , long long b){
        if(b == 0){
            return a;
        }
        // if(a == 0){
        //     return b;
        // }
        // if(a==b){
        //     return a;
        // }
        // if(a > b){
        //     return gcd(a-b , b);
        // }
        // return gcd(a , b-a);
        return gcd(b , a%b);

    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long gcdl = gcd(A,B);
        long long lcm = (A*B)/gcdl;
        
        return {lcm , gcdl};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
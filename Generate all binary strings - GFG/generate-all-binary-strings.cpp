//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(string str , vector<string>& res, int num){
        if(str.length()==num){
            res.push_back(str);
            return;
        }
        int len= str.length();
        if(len > 0 and str[len-1] == '1'){
            str.push_back('0');
            solve(str , res,num);
        }
        else{
            str.push_back('0');
            solve(str,res,num);
            str.pop_back();
            str.push_back('1');
            solve(str,res,num);
        }
    }

    void generateBinaryStrings(int num){
        //Write your code
        vector<string> res;
        
        solve("",res , num);
        
        for(auto it : res){
            cout<<it<<" ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
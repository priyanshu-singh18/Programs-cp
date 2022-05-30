// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    vector<string> ans;
	    
	    void solve( int n ,string& temp, string& S ,vector<int>& freq){
	        if(temp.size() == n){
	            ans.push_back(temp);
	            return;
	        }
	        for(int i = 0;i<n;i++){
	           if(freq[i])
	                continue;
	           if(i>0 and S[i-1]==S[i] and !freq[i-1])
	                continue;
	           
	           freq[i] = 1;
	           temp.push_back(S[i]);
	           solve(n,temp,S,freq);
	           freq[i] =  0;
	           temp.pop_back();
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int n = S.length();
		    sort(S.begin(),S.end());
		    vector<int> freq(n,0);
		    string temp="";
		    solve(n,temp,S,freq);
		  //  sort(ans.begin(),ans.end());
		    return ans;
		}


};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
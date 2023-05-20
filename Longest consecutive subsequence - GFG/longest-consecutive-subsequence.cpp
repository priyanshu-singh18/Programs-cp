//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      map<int,int> mop;
      
      for(int i=0;i<N;i++){
          mop[arr[i]]++;
      }
       map<int,int> :: iterator it,prev;
       it =mop.begin();
       prev = it;
       it++;
       
       int cnt=1, ans = 1;
       
       while(it!=mop.end()){
           if(it->first  == prev->first +1){
               cnt++;
               ans = max(ans , cnt);
           }
           else{
               cnt=1;
           }
           it++,prev++;
       }

       return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
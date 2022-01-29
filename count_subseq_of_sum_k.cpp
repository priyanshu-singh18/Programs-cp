#include<bits/stdc++.h>
using namespace std;

int solve(int i, int s, int n, int sum, vector<int>& d, int arr[]){
  if(i==n){
    if(s==sum){
      return 1;
    }
    return 0;
  }
  s+=arr[i];
  d.push_back(arr[i]);
  int l = solve(i+1,s,n,sum,d,arr);
  
  d.pop_back();
  s-=arr[i];
  int r =  solve(i+1,s,n,sum,d,arr);
 
  return l+r;
}

int main(){
  int n=3;
  vector<int> d;
  int arr[] = {1,2,3};
  int sum=3;
   cout<<solve(0,0,n,sum,d,arr);
  return 0;
}
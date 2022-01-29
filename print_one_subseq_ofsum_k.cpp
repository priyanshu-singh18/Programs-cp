#include<bits/stdc++.h>
using namespace std;

bool solve(int i, int s, int n, int sum, vector<int>& d, int arr[]){
  if(i==n){
    if(s==sum){
      for(auto it : d){
        cout<<it<<" ";
      }
      return true;
    }
    return false;
  }
  s+=arr[i];
  d.push_back(arr[i]);
  if(solve(i+1,s,n,sum,d,arr)){
    return true;
  }
  d.pop_back();
  s-=arr[i];
  if(solve(i+1,s,n,sum,d,arr)){
    return true;
  }
  return false;
}

int main(){
  int n=3;
  vector<int> d;
  int arr[] = {1,2,1};
  int sum=3;
  bool op = solve(0,0,n,sum,d,arr);
  return 0;
}
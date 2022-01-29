#include<bits/stdc++.h>
using namespace std;

void solve(int i, int s, int n, int sum, vector<int>& d, int arr[]){
  if(i==n){
    if(s==sum){
      for(auto it : d){
        cout<<it<<" ";
      }
      cout<<endl;
    }
    return;
  }
  s+=arr[i];
  d.push_back(arr[i]);
  solve(i+1,s,n,sum,d,arr);
  d.pop_back();
  s-=arr[i];
  solve(i+1,s,n,sum,d,arr);
}

int main(){
  int n=3;
  vector<int> d;
  int arr[] = {1,2,3};
  int sum=3;
  solve(0,0,n,sum,d,arr);
  return 0;
}
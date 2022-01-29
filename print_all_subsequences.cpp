#include <bits/stdc++.h>
using namespace std;

void solve(int i, int n, vector<int>&d,int arr[]){
  if(i==n){
    for(auto it : d){
      cout<<it<<" ";
    }
    cout<<endl;
    return;
  }
  d.push_back(arr[i]);
  solve(i+1,n,d,arr);
  d.pop_back();
  solve(i+1,n,d,arr);
}

int main(){
  vector<int> d;
  int n=3;
  int arr[] = {1,2,3};
  solve(0,n,d,arr);
  return 0;
}
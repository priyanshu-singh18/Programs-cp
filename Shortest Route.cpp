#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		long long int N,M,A[100000],B[100000],r,l;
		cin>>N>>M;
		for(int i=1;i<=N;i++){
			cin>>A[i];
		}
		for(int i=1;i<=M;i++){
			cin>>B[i];
		}
		vector<int> v;
		for(int i =1 ;i<=M;i++){
			int time = -1;
			r=l=B[i];
			while(r<=N && l>=1){
				if(r==B[i] && (A[r]==1 || A[r]==2)){
						time=1;
						v.push_back(0);
						break;
				}
				if(A[r]==2 && A[l]==0){
					time = r-B[i];
					v.push_back(time);
					break;
				}
				else if(A[r]==0 && A[l]==1){
					time = B[i]-l;
					v.push_back(time);
					break;
				}
				else if(A[r]==2 && A[l]==1 ){
					time = r-B[i];
					v.push_back(time);
				}
				r++;l--;
			}
			if(time==-1){
				v.push_back(-1);
			}

		}

				for(int i = 0 ;i<v.size();i++){
					cout<<v[i]<<" ";
				}
		
	}
	return 0;
}
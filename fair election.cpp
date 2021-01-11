#include <bits/stdc++.h>
using namespace std;


int main() {
	int T;
	cin>>T;
    
	while(T--){
        int N,M,A[1000],B[1000],sum1=0,sum2=0,swap=0,temp;	   
	    cin>>N>>M;
	    int k=0,l=M-1;
	    for(int i =0;i<N;i++){
	        cin>>A[i];
	        sum1+=A[i];
	    }
	    for(int i=0;i<M;i++)
	    {
	        cin>>B[i];
	        sum2+=B[i];
	    }
	   sort(A,A+N);
	   sort(B,B+M);
	    while(sum1<=sum2 && k<N && l>=0){
	         if(A[k]<B[l]){
	          swap++;
	           sum1 = sum1 - A[k] + B[l];
	           sum2 = sum2 + A[k] - B[l];
	           temp = A[k];
	           A[k] = B[l];
	           B[l] = temp;
	           k++;l--;
	         }
	         else{
	             break;
	         }
	           
	        
	    }
	    if(sum1<=sum2){
	        cout<<-1<<endl;
	    }
	    else{
	        cout<<swap<<endl;
	    }
	}
	return 0;
}
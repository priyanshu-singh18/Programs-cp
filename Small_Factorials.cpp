
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,N;
	cin>>T;
	while(T--)
	{
	   cin>>N;
	  int i=1, arr[200],m=0,temp=0;
        arr[0]=1;
         while(i<=N){
       for(int j=0; j<=m;j++){
           arr[j]=(arr[j]*i)+temp;
           temp=arr[j]/10;
           arr[j]=arr[j]%10;
       }
       while(temp){
           m++;
           arr[m]=temp%10;
           temp=temp/10;
       }
       i++;
       }
	for(int i=m;i>=0;i--)
       {
           cout<<arr[i];
       }
       cout<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;


int main() {
	int T;
	cin>>T;
    
	while(T--){
        int n,k,x,y,c,count=0,x1,y1,m,k1,coll=0,temp;
        cin>>n>>k>>x>>y;
        k1=k%4;
        x1 = x;
        y1 = y;
        if(k1==0)
            k1=4;
        while(coll<=k1){
            if(x1==y1){
                coll++;
            }
            else if(x1>y1){
                coll++;
                y1=n+y1-x1;
                x1=n;
                if(k1>=2 && coll==1){
                    coll++;
                    temp=x1;
                    x1=y1;
                    y1=temp;
                }
                if(k1>=3 && coll==2){
                    y1=y1-x1;
                    x1=0;
                    coll++;
                }
                if(k1==4 && coll==3){
                    coll++;
                    temp=x1;
                    x1=y1;
                    y1=temp;
                }
                
            }
            else if(y1>x1){
                coll++;
                 x1 = n-y1+x1;
                 y1=5;
                if(k1>=2 && coll==1){
                    coll++;
                    temp=x1;
                    x1=y1;
                    y1=temp;
                }
                if(k1>=3 && coll==2){
                    x1=x1-y1;
                    y1=0;
                    coll++;
                }
                if(k1==4 && coll==3){
                    coll++;
                    temp=x1;
                    x1=y1;
                    y1=temp;
                }
            }
        }
        if(coll==1){
            cout<<n<<" "<<n<<endl;
        }
        else{
            cout<<x1<<" "<<y1<<endl;
        }
      
	}
	return 0;
}
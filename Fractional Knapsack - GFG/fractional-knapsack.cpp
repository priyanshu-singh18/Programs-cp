// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n, [] (Item a , Item b){
           double a1 = (double)a.value / (double)a.weight; 
           double b1 = (double)b.value / (double)b.weight; 
           return a1>b1;
        });
        
        double profit=0;
        int cost=0;
        
        for(int i=0;i<n;i++){
            if((double)arr[i].weight + cost <= W){
                profit+=(double) arr[i].value;
                cost+=arr[i].weight; 
            }
            else{
                int rem = W - cost;
                profit+=((double)rem/(double)arr[i].weight)*arr[i].value;
                break;
            }
        }
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> vop;
        for(int i=0;i<n;i++)
            vop.push_back({start[i],end[i]});
        
        sort(vop.begin(),vop.end(), [] (pair<int,int> a, pair<int,int> b){
           return a.second < b.second;
        });
        
        int count = 0,prev = -1;
        
        for(int i=0;i<n;i++){
            if(vop[i].first > prev){
                prev = vop[i].second;
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> minEffort(row , vector<int> (col , 1e9));
        
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>>> qop;
        qop.push({0,{0,0}});
        minEffort[0][0] = 0;
        
        vector<pair<int,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!qop.empty()){
            auto temp = qop.top();
            qop.pop();
            
            int diff = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            
            if(x == row-1 and y == col-1){
                return diff;
            }
            
            for(auto move : moves){
                int x1 = move.first + x;
                int y1 = move.second + y;
                
                if(x1>=0 and y1>=0 and x1<row and y1<col){
                    int newEffort = max(diff , abs(heights[x1][y1]-heights[x][y]));
                    
                    if(newEffort < minEffort[x1][y1]){
                        minEffort[x1][y1] = newEffort;
                        qop.push({newEffort,{x1,y1}});
                    }
                    
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        queue<pair<int,int>> qop ; 
        qop.push({sr , sc});
        int row = image.size();
        int col = image[0].size();
        int prevColor = image[sr][sc];
        image[sr][sc] = newColor;
        
           if(prevColor == newColor){
            return image;
        }
        
        
        vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!qop.empty()){
            int n = qop.size();
            while(n--){
                int x = qop.front().first;
                int y = qop.front().second;
                qop.pop();
                
                for(auto move : moves){
                    int x1 = move.first + x;
                    int y1 = move.second + y;
                    
                    if(x1>=0 && x1<row && y1<col && y1>=0 && image[x1][y1]==prevColor){
                        qop.push({x1,y1});
                        image[x1][y1] = newColor;
                    }
                }
            }
        }
        return image;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
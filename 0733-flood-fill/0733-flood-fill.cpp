class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size() , n = image[0].size();
        queue<pair<int,int>> qop;
        int original_color = image[sr][sc];
        image[sr][sc] = color;
        qop.push({sr,sc});

        while(!qop.empty()){
            int x = qop.front().first;
            int y = qop.front().second;

            qop.pop();

            for(auto direction : directions){
                int x1 = x+direction.first;
                int y1 = y+direction.second;

                if(x1<0 || y1<0 || x1==m || y1==n || image[x1][y1] == color){
                    continue;
                }

                if(image[x1][y1] != original_color) continue;
                image[x1][y1] = color;
                qop.push({x1,y1});
            }
        }
        return image;
    }
};
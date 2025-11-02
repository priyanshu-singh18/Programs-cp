class Solution {
public:
    void dfs(int i, int j, char direction, vector<vector<int>>& vis , map<pair<int,int>,int>& obstacles) {

        int m = vis.size();
        int n = vis[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }

        if (obstacles.find({i, j}) != obstacles.end()) {
            return;
        }

        vis[i][j] = 1;

        if (direction == 'u') {
            dfs(i - 1, j, 'u', vis, obstacles);
        }
        if (direction == 'd') {
            dfs(i + 1, j, 'd', vis,obstacles);
        }
        if (direction == 'l') {
            dfs(i, j - 1, 'l', vis,obstacles);
        }
        if (direction == 'r') {
            dfs(i, j + 1, 'r', vis,obstacles);
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));

        map<pair<int, int> , int> obstacles;

        for (auto it : guards) {
            vis[it[0]][it[1]] = 1;
            obstacles[{it[0] , it[1]}] = 1;
        }

        for (auto it : walls) {
            vis[it[0]][it[1]] = 1;
            obstacles[{it[0] , it[1]}] = 1;
        }

        for (auto it : guards) {
            dfs(it[0] - 1, it[1], 'u', vis,obstacles);
            dfs(it[0] + 1, it[1], 'd', vis,obstacles);
            dfs(it[0], it[1] - 1, 'l', vis,obstacles);
            dfs(it[0], it[1] + 1, 'r', vis,obstacles);
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
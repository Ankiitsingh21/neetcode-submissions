class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // dist[i][j]=0;
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
                // vis[i][j]=true;
            }
        }
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol]==2147483647) {
                    // vis[nrow][ncol] = true;
                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        // grid = dist;
        return;
    }
};

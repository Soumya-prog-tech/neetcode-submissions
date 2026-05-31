class Solution {
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i =0;i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != INT_MAX) {
                    continue;
                }
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
};

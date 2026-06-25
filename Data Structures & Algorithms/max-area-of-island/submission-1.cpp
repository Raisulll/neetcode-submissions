class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    cout << " i, j " << i << " " << j << endl;
                    ans = max(ans, bfs(grid, i, j));
                    cout << ans << endl;
                }
            }
        }
        return ans;
    }
    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = -1;
        int area = 1;
        while (!q.empty()) {
            auto [a, b] = q.front();
            cout << "a,b " << a << " " << b << endl;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = a + dx[i];
                int ny = b + dy[i];
                if (nx >= 0 and nx < grid.size() and ny >= 0 and ny < grid[0].size() and
                    grid[nx][ny] == 1) {
                    area++;
                    q.push({nx, ny});
                    grid[nx][ny] = -1;
                    cout << "here " << q.size() << endl;
                }
            }
        }
        return area;
    }
};

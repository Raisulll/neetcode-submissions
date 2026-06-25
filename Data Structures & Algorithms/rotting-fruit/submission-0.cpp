int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = INT_MAX;
                }
                if (grid[i][j] == 2) {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 and nx < r and ny >= 0 and ny < c) {
                    if (grid[nx][ny] != 0 and grid[nx][ny] > grid[x][y] + 1) {
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == INT_MAX) {
                    return -1;
                } else {
                    ans = max(ans, grid[i][j]);
                }
            }
        }
        return ans;
    }
};

class Solution {
    int r, c;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r = heights.size(), c = heights[0].size();
        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));
        for (int i = 0; i < r; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, c - 1);
        }
        for (int i = 0; i < c; ++i) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, r - 1, i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (pacific[i][j] and atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& arr, int r, int c) {
        arr[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (check(nr, nc) and !arr[nr][nc] and heights[nr][nc]>=heights[r][c]) {
                dfs(heights, arr, nr, nc);
            }
        }
    }
    bool check(int nr, int nc) { return nr >= 0 and nr < r and nc >= 0 and nc < c ? true : false; }
};

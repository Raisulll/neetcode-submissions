class Solution {
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};
    int m, n;

   public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    vector<pair<int, int>> idx;
                    bool flag = false;
                    dfs(board, idx, i, j, flag);
                    if(flag){
                        for(auto [a,b]:idx){
                            board[a][b]='O';
                        }
                    }else{
                        for(auto [a,b]:idx){
                            board[a][b]='X';
                        }
                    }
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, vector<pair<int, int>>& idx, int r, int c, bool& flag) {
        if (r == 0 or r == m - 1 or c == 0 or c == n - 1) flag = true;
        idx.push_back({r, c});
        board[r][c]='V';
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (check(nr, nc) and board[nr][nc] == 'O') {
                dfs(board, idx, nr, nc, flag);
            }
        }
    }
    bool check(int r, int c) { return r >= 0 and r < m and c >= 0 and c < n; }
};

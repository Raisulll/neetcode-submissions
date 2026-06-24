class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (!row.count(board[i][j])) {
                        row.insert(board[i][j]);
                    } else {
                        cout<<"row\n";
                        return false;
                    }
                }
            }
        }
        // col
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> col;
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (!col.count(board[j][i])) {
                        col.insert(board[j][i]);
                    } else {
                        cout<<"Col\n";
                        return false;
                    }
                }
            }
        }

        // 3x3
        for (int sq = 0; sq < 9; ++sq) {
            unordered_set<char> st;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int r = (sq / 3) * 3 + i;
                    int c = (sq % 3) * 3 + j;
                    if (board[r][c] != '.') {
                        if (!st.count(board[r][c])) {
                            st.insert(board[r][c]);
                        } else {
                            cout<<"Sq\n";
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

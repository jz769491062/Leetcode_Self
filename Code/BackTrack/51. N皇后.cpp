class Solution {
public:
vector<vector<string>> res;
    bool canPlace(vector<string>& board, int x, int y) {
        // 检查竖排
        for (int i = 0; i < board.size(); i++) {
            if (i == x) continue;
            if (board[i][y] == 'Q') {
                return false;
            }
        }
        // 检查横排
        for (int i = 0; i < board.size(); i++) {
            if (i == y) continue;
            if (board[x][i] == 'Q') {
                return false;
            }
        }
        //注意！因为一行一行放的，所以我们只关心左上方和右上方的斜线即可
        //左上方
        for (int i = x, j = y; i >=0 && j >=0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // 右上方
        for (int i = x, j = y; i >=0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<string>& board, int currRow, int n) {
        if (currRow == n) {
            res.push_back(board);
        }
        for (int i = 0; i < n; i++) {
            if (canPlace(board, currRow, i)) {
                board[currRow][i] = 'Q';
                backtrack(board, currRow + 1, n);
                board[currRow][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string sLine = "";
        for (int i = 0; i < n; i++) {
            sLine += ".";
        }
        for (int i = 0; i < n; i++) {
            board.push_back(sLine);
        }
        backtrack(board, 0, n);
        return res;
    }
};https://leetcode.cn/problems/n-queens/
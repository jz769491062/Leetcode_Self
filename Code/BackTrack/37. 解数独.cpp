// https://leetcode.cn/problems/sudoku-solver/description/
// 上界 O(9^M)，但是我们找到一个解就返回，实际更快
class Solution {
public:
    // 为了降低复杂度，backtrack return bool, 找到一个解就彻底返回
    bool backtrack(vector<vector<char>>& board, int x, int y) {
        // 找到一个解就返回
        if (x == 9) return true;
        // 开始下一行的解数独
        if (y == 9) {
            return backtrack(board, x + 1, 0);
        }
        if (board[x][y] != '.') {
            return backtrack(board, x, y + 1);
        }
        for (char c = '1'; c <= '9'; c++) {
            if (!isValid(board, x, y, c)) continue;
            board[x][y] = c;
            // 找到一个解就返回
            if (backtrack(board, x, y + 1)) return true;
            board[x][y] = '.';
        }
        return false; // 穷举1-9后还没有解，false
    }

    bool isValid(vector<vector<char>>& board, int x, int y, char n) {
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == n) return false;
            if (board[i][y] == n) return false;
            // 一排排遍历小宫格:00 01 02 10 11 12这样的顺序
            if (board[(x/3) * 3 + (i/3)][(y/3) * 3 + (i%3)] == n) return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};
// https://leetcode.cn/problems/sudoku-solver/description/
class Solution {
    vector<vector<bitset<9>>> cells;
    vector<bitset<9>> rows, cols;
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(9);
        cols.resize(9);
        cells.resize(3, vector<bitset<9>>(3)); // 九宫格
        int emptyCount = 0;
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    emptyCount++;
                    continue;
                }
                int num = board[i][j] - '1';
                rows[i] |= 1 << num;
                cols[j] |= 1 << num;
                cells[i/3][j/3] |= 1 << num;
            }
        }
        dfs(board, emptyCount);
    }

    bitset<9> getNumCanFill(int x, int y) {
        return ~(rows[x] | cols[y] | cells[x/3][y/3]);
    }

    pair<int, int> getNextFewestChoiceCell(vector<vector<char>>& board) {
        pair<int, int> res;
        int mincnt = 10;
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') continue;
                bitset<9> curr = getNumCanFill(i, j);
                if (curr.count() >= mincnt) continue;
                res = {i, j};
                mincnt = curr.count();
            }
        }
        return res;
    }

    bool dfs(vector<vector<char>>& board, int emptyCount) {
        if (emptyCount == 0) return true;
        pair<int, int> nextToFill = getNextFewestChoiceCell(board);
        int x = nextToFill.first, y = nextToFill.second;
        bitset<9> options = getNumCanFill(x, y);
        for (int i = 0; i < options.size(); i++) {
            if (options[i] == 0) continue;
            rows[x][i] = 1;
            cols[y][i] = 1;
            cells[x/3][y/3][i] = 1;
            board[x][y] = '1' + i;
            if (dfs(board, emptyCount - 1)) {
                return true;
            }
            board[x][y] = '.';
            rows[x][i] = 0;
            cols[y][i] = 0;
            cells[x/3][y/3][i] = 0;
        }
        // 没得填充了但还没填完空，false
        return false;
    }
};






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
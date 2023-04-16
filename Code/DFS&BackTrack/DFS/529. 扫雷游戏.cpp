class Solution {
    vector<vector<bool>> visited;
    int m, n;
    vector<vector<int>> dir = {{-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        visited.resize(m, vector<bool>(n));
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if (board[click[0]][click[1]] == 'E') {
            dfs(board, click[0], click[1]);
        }
        return board;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (visited[x][y]) {
            return;
        }
        visited[x][y] = true;
        char mines = getMine(board, x, y);
        if (mines > '0') {
            board[x][y] = mines;
            return;
        } else {
            board[x][y] = 'B';
            for (vector<int>& di : dir) {
                int nx = x + di[0];
                int ny = y + di[1];
                if (!inArea(nx, ny)) {
                    continue;
                }
                dfs(board, nx, ny);
            }
        }
    }

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }

    char getMine(vector<vector<char>>& board, int x, int y) {
        char count = '0';
        for (vector<int>& di : dir) {
            int nx = x + di[0];
            int ny = y + di[1];
            if (!inArea(nx, ny)) {
                continue;
            }
            if (board[nx][ny] == 'M') {
                count++;
            }
        }
        return count;
    }
};// https://leetcode.cn/problems/minesweeper/description/
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
            bfs(board, click[0], click[1]);
        }
        return board;
    }

    void bfs(vector<vector<char>>& board, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        while (!q.empty()) {
            // int sz = q.size();
            // for (int i = 0 ; i < sz; i++) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                char mines = getMine(board, cx, cy);
                if (mines > '0') {
                    board[cx][cy] = mines;
                    continue;
                }
                board[cx][cy] = 'B';
                for (vector<int>& di : dir) {
                    int nx = cx + di[0];
                    int ny = cy + di[1];
                    if (!inArea(nx, ny)) {
                        continue;
                    }
                    if (visited[nx][ny]) {
                        continue;
                    }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            // }
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
class Solution {
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<vector<bool>> visited;
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        visited.resize(m, vector<bool>(n));
        // 先把四个边的dfs一下，这样和边界O联通的就提前visited了
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[m - 1][i] == 'O') dfs(board, m - 1, i);
        }
        // 然后剩下的没有visited的O就是需要淹没的
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (visited[x][y] || board[x][y] == 'X') return;
        int m = board.size(), n = board[0].size();
        visited[x][y] = true;
        for (vector<int>& d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (inArea(m, n, nx, ny)) {
                dfs(board, nx, ny);
            }
        }
    }

    bool inArea(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/surrounded-regions/description/
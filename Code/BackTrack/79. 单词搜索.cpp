class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        visited.resize(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int start, int x, int y) {
        int m = board.size(), n = board[0].size();
        if (start == word.size() - 1) {
            return word[start] == board[x][y];
        }
        if (word[start] == board[x][y]) {
            visited[x][y] = true;
            for (vector<int>& d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (inArea(m, n, nx, ny) && !visited[nx][ny] && dfs(board, word, start + 1, nx, ny)) {
                    return true;
                }
            }
            visited[x][y] = false;
        }
        return false;
    }

    bool inArea(int m, int n , int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/word-search/description/
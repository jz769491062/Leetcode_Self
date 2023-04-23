class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        visited.resize(m, vector<bool>(n));
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        vector<pair<int, int>> toPaint;
        int startColor = image[sr][sc];
        toPaint.push_back({sr, sc});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            int curr = image[r][c];
            q.pop();
            for (vector<int>& di : dir) {
                int nx = r + di[0];
                int ny = c + di[1];
                if (!inArea(nx, ny, m, n)) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                if (image[nx][ny] == startColor) {
                    toPaint.push_back({nx, ny});
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        for (pair<int, int>& p : toPaint) {
            image[p.first][p.second] = color;
        }
        return image;
    }

    bool inArea(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/flood-fill/description/
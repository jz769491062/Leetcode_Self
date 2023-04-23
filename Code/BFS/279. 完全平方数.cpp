// https://leetcode.cn/problems/perfect-squares/description/
// 可以动态规划，但是其实也可以BFS找最小需要的平方数。
// 抽象成一幅图, 12 指向 12-1, 12-4, 12-9……在这个图BFS可以用深度算出需要多少个平方数。
// O(N * rootN)
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n + 1);
        q.push(n);
        visited[n] = true;
        int depth = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                for (int j = 1; j * j <= curr; j++) {
                    if (j * j == curr) {
                        return depth;
                    }
                    int next = curr - j * j;
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};
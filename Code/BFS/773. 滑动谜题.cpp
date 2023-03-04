class Solution {
/*
观察上图就能发现，如果二维数组中的某个元素 e 在一维数组中的索引为 i，那么 e 的左右相邻元素在一维数组中的索引就是 i - 1 和 i + 1，而 e 的上下相邻元素在一维数组中的索引就是 i - n 和 i + n，其中 n 为二维数组的列数。
这样，对于 m x n 的二维数组，我们可以写一个函数来生成它的 neighbor 索引映射
*/
    vector<vector<int>> neighbors = {
        {1, 3},
        {0, 4, 2},
        {1, 5},
        {0, 4},
        {3, 1, 5},
        {4, 2}
    };
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2, n = 3;
        string target = "123450";
        string start;
        // 起始状态
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start += to_string(board[i][j]);
            }
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            // 注意，一次扩散队列中所有元素
            for (int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();
                if (curr == target) {
                    return res;
                }
                int zeroIndex = 0;
                // 找到0的索引
                for (; curr[zeroIndex] != '0'; zeroIndex++);
                for (int neighbor : neighbors[zeroIndex]) {
                    // 交换，产生新state，加入queue
                    string newState = curr;
                    swap(newState[neighbor], newState[zeroIndex]);
                    if (!visited.count(newState)) {
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            res++; // 注意是在末尾更新移动步数，直到队列元素都被处理完才统计这一步数。
        }
        return -1;
    }
};// https://leetcode.cn/problems/sliding-puzzle/description/
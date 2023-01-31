// https://leetcode.cn/problems/spiral-matrix/
// 用4个变量控制上右下左的遍历边界
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int topBound = 0, bottBound = m - 1, leftBound = 0, rightBound = n - 1;
        vector<int> res;
        while (res.size() < m * n) {
            // 注意顺序，上右下左，不可上下左右顺序收敛4个边界
            if (topBound <= bottBound) {
                for (int i = leftBound; i <= rightBound; i++) {
                    res.push_back(matrix[topBound][i]);
                }
                topBound++;
            }
            if (leftBound <= rightBound) {
                for (int i = topBound; i <= bottBound; i++) {
                    res.push_back(matrix[i][rightBound]);
                }
                rightBound--;
            }
            if (topBound <= bottBound) {
                for (int i = rightBound; i >= leftBound; i--) {
                    res.push_back(matrix[bottBound][i]);
                }
                bottBound--;
            }
            if (leftBound <= rightBound) {
                for (int i = bottBound; i >= topBound; i--) {
                    res.push_back(matrix[i][leftBound]);
                }
                leftBound++;
            }
        }
        return res;
    }
};
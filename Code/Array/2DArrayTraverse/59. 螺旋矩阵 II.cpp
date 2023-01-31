// https://leetcode.cn/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int topBound = 0, bottBound = n - 1, leftBound = 0, rightBound = n - 1;
        int curr = 1;
        while (curr <= n * n) {
            // 注意顺序，上右下左，不可上下左右顺序收敛4个边界
            if (topBound <= bottBound) {
                for (int i = leftBound; i <= rightBound; i++) {
                    res[topBound][i] = curr;
                    curr++;
                }
                topBound++;
            }
            if (leftBound <= rightBound) {
                for (int i = topBound; i <= bottBound; i++) {
                    res[i][rightBound] = curr;
                    curr++;
                }
                rightBound--;
            }
            if (topBound <= bottBound) {
                for (int i = rightBound; i >= leftBound; i--) {
                    res[bottBound][i] = curr;
                    curr++;
                }
                bottBound--;
            }
            if (leftBound <= rightBound) {
                for (int i = bottBound; i >= topBound; i--) {
                    res[i][leftBound] = curr;
                    curr++;
                }
                leftBound++;
            }
        }
        return res;
    }
};
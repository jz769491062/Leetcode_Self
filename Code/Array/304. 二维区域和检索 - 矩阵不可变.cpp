// 参考此图 https://labuladong.gitee.io/algo/images/%e5%89%8d%e7%bc%80%e5%92%8c/5.jpeg
// https://leetcode.cn/problems/range-sum-query-2d-immutable/
class NumMatrix {
public:
vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        // 定义：preSum[i][j]代表以matrix[i-1][j-1]为右下角的矩阵的和
        // 意味着preSum数组第一行和第一列都是0
        preSum.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        // 一行一行遍历赋值
        // preSum当前格子的=左边格子 + 上边格子 - 左上角格子 + 当前matrix格子数字
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                preSum[i + 1][j + 1] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // sum = 全部面积-左边一条-上边一条+左上重复计算的区域
        int res = preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1]
         - preSum[row1][col2 + 1] + preSum[row1][col1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
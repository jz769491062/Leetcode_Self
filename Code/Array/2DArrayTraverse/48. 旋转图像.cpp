// https://leetcode.cn/problems/rotate-image/
// 顺时针旋转90度：左上-右下斜线为中心，镜像反转；然后反转每一行的数字。
// 逆时针90度：右上-左下斜线为中心镜像反转，然后反转每一行。
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //左上-右下为线镜像反转
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {//注意j = i
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 然后反转每一行的数字
        for (vector<int>& v: matrix) {
            reverse(v.begin(), v.end());
        }
    }
};
class Solution {
public:
    int minInsertions(string s) {
        // 对于当前子串，最少的插入次数是?
        // 如果相等就抄上一子串的结果[i+1][j-1]，不相等就分别看[i+1, j]和[i, j-1]哪个能给出最小的结果再+1
        // 这种子序列题一般都是动态规划 O(n^2)
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // 然后事实上只用到矩阵的一半，可以从左到右斜着遍历或者从下到上横着遍历计算
        for (int i = n - 1; i >=0; i--) {
            // 注意j = i + 1不是j = i
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    // 下格和左格，注意是i + 1. 再+1
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[0][n - 1];
    }
};// https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
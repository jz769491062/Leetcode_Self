class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 对于当前子串，最长的回文子序列是多少?
        // 两头找，如果相等就+2，不相等就分别看[i+1, j]和[i, j-1]哪个能给出最大的结果
        // 这种子序列题一般都是动态规划 O(n^2)
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化斜线上的为1，一个字符回文长度是1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        // 然后事实上只用到矩阵的一半，可以从左到右斜着遍历或者从下到上横着遍历计算
        for (int i = n - 1; i >=0; i--) {
            // 注意j = i + 1不是j = i
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // 下格和左格，注意是i + 1
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};// https://leetcode.cn/problems/longest-palindromic-subsequence/description/
// https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA
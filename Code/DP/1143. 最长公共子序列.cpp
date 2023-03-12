// https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484486&idx=1&sn=0bdcb94c6390307ea32427757ec0072c&chksm=9bd7fa4eaca073583623cdb93b05dc9e1d0757b25697bb40b29b3e450124e929ff1a8eaac50f&scene=178&cur_album_id=1318896187793260544#rd
// https://leetcode.cn/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                // 注意text索引- 1
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // 都已经不相等了，dp[i-1][j-1]的结果肯定没有剩下2种大，只比较剩下2种即可
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};


class Solution {
    vector<vector<int>> memo;
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(), vector<int>(text2.size(), -1));
        return DP(text1, text2, 0, 0);
    }

    int DP(string& text1, string& text2, int i, int j) {
        int m = text1.size(), n = text2.size();
        if (i == m || j == n) return 0;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        // 注意相等的话就不要用max了，反正肯定是加进公共子序列的
        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + DP(text1,text2, i + 1, j + 1);
            return memo[i][j];
        } else {
            // 哪个长就选哪个，不以其中一个字符串为基准
            memo[i][j] = max(DP(text1,text2, i + 1, j), DP(text1, text2, i, j + 1));
            return memo[i][j];
        }
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        int m = word1.size(), n = word2.size();
        // 注意n+1行是word2，m+1列是word1
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        // 注意这里初始化成最大可能的编辑距离，而不是INT_MAX
        for (int i = 1; i <= m; i++) dp[0][i] = i;
        for (int i = 1; i <= n; i++) dp[i][0] = i;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (word1[j - 1] == word2[i - 1]) {
                    // 注意，相等时要照抄上一格的，不要再进行Min计算了，因为根本就不需要增删改
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 需要增删改的时候才用Min
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        return dp[n][m];
    }
};// https://leetcode.cn/problems/edit-distance/description/


class Solution {
    vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        memo.resize(m, vector<int>(n, -1));
        return DP(word1, word2, m - 1, n - 1);
    }

    int DP(string& word1, string& word2, int i, int j) {
        // 注意base case: 越界相当于和""进行匹配，所以return非零的行列索引再+1
        // 为什么从m-1, n-1开始而不是0,0开始，就是因为在第0行才让我们的base case更方便地控制
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (word1[i] == word2[j]) {
            memo[i][j] = DP(word1, word2, i - 1, j - 1);
        } else {
            memo[i][j] = 1 + Min(
                DP(word1, word2, i - 1, j - 1),// 改
                DP(word1, word2, i - 1, j),// 删
                DP(word1, word2, i, j - 1) // 插入
            );
        }
        return memo[i][j];
    }

    int Min(int a, int b, int c) {
        return min(a, min(b, c));
    }
};
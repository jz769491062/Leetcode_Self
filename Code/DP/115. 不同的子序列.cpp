class Solution {
    vector<vector<int>> memo;
public:
    int numDistinct(string s, string t) {
        memo = vector(s.size(), vector<int>(t.size(), -1));
        return dp(s, t, 0, 0);
    }

    int dp(string& s, string& t, int i, int j) {
        // base case
        if (s.size() - i < t.size() - j) {
            // s[i..] 比 t[j..] 还短，必然没有匹配的子序列
            return 0;
        }
        if (j == t.size()) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int res = 0;
        if (s[i] == t[j]) {
            // 匹配，两种情况，累加关系
            res += dp(s, t, i + 1, j + 1) + dp(s, t, i + 1, j);
        } else {
            // 不匹配，在 s[i+1..] 的子序列中计算 t[j..] 的出现次数
            res += dp(s, t, i + 1, j);
        }
        memo[i][j] = res;
        return res;
    }
};// https://leetcode.cn/problems/distinct-subsequences/description/
// https://leetcode.cn/problems/k-inverse-pairs-array/description/
class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int kInversePairs(int n, int k) {
    // dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-(i-1)]
    // dp[i][j-1] =            dp[i-1][j-1] + ... + dp[i-1][j-1-(i-2)] + dp[i-1][j-1-(i-1)]
    // // 上减下、移项，才有
    // dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-i]
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        // base case
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= min(k, (i - 1) * i / 2); j++) {
                dp[i][j] = (long long)((long long)(j >= 1 ? dp[i][j - 1] : 0) 
                + (long long)dp[i - 1][j] 
                - (long long)(j >= i ? dp[i - 1][j - i] : 0) + MOD) % MOD;
            }
        } 
        return dp[n][k];
    }
};
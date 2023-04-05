class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        dp[0][0] = true; // 注意base case只有这一个
        for (int i = 1; i < n; ++i) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int lastDist = stones[i] - stones[j];
                if (lastDist > j + 1) {
                    break;
                }
                // 注意是dp[j]来看上一步
                dp[i][lastDist] = dp[j][lastDist - 1] || dp[j][lastDist] || dp[j][lastDist + 1];
                if (i == n - 1 && dp[i][lastDist] == true) {
                    return true;
                }
            }
        }
        return false;
    }
};// https://leetcode.cn/problems/frog-jump/description/?company_slug=huawei
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int i = 0; i < n; i++) { // 注意索引范围
            for (int j = 0; j <= k; j++) { // 注意索引范围
                // 此处base case初始化原则：赋予一个可能的最小值，总之方便数值的更新
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[i];
            }
        }
        for (int i = 1; i < n; i++) {// 注意索引范围
            for (int j = 1; j <= k; j++) { // 注意索引范围
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }
};// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
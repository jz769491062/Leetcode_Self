class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 冷冻期意味着再次买入的时候我们得看i-2的卖出后利润而不是i-1的
        // 所以处理好i-2的base case，也就是还不存在上一笔交易时的情况，就是-prices[i]的情况
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
            dp[i][1] = -prices[i];
        }
        // 处理起始base case
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            // 处理base case i - 2
            if (i - 2 == -1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], -prices[i]); // 注意是0-prices[i]，这时还没有上一笔
                continue; // 别忘了continue
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);

            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);// 注意i-2
        }
        return dp[n - 1][0];
    }
}; // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 和121只能买卖一次很相似，但是这次k无穷大
        // 不同于121，不能重复使用dp[i - 1][0]，这次可以多次交易所以dp[i - 1][0]是必要的，而不会打乱我们的结果
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
            dp[i][1] = -INT_MAX; // 更新数值用，这样能记录买完股票后当前收益，毕竟一开始负数，至少<=-prices[i]
        }
        // 处理起始base case，不做为0，买了为-prices[0]
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 和121区别在dp[i - 1][0] - prices[i]
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
}; // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
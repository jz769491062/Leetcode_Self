class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
            // dp[i - 1][0] 永远是0，省略
            // 这个省略是必要的，因为这题交易次数k = 1，到达状态1看的是上笔交易卖出后的结果，但本体不存在上一笔交易，
            // 固定为我们初始化的0，所以简化为 0 - prices[i]。用了dp[i - 1][0]可能是之前某步的计算结果，但那是卖出的，也就是说已经交易完成1次了，那就不能再用dp[i - 1][0]一次了。所以这里一定要写成0
            dp[i][1] = max(dp[i - 1][1], - prices[i]);
        }
        return dp[n - 1][0];
    }
}; // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
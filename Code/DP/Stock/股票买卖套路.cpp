// 每天三个选择：买（卖完后或者第一次操作）、卖（买后）、空（买后、卖后）
// 每天有三个状态：天数、最多允许交易几次、现在手里有没有股票。
// 所以dp[天数N][能交易几次K][手里有无股票，0或1] n i=0~N-1, k 1~K
// 所以答案在dp[N-1][k][0]
// 状态机：0 buy 到 1,1 sell 到 0, rest 维持当前状态。
// 所以有两种方法达到0：本来就没股票选择rest，或者今天卖掉刚刚->0.
// 所以有两种方法达到1：有股票但今天不卖rest，或者今天买了刚刚->1.
for i = 0, i <= N - 1, i++
    for k = 1; k <= K; k++
        for s = {0, 1}:
        // 没有股票时，不做保持0=copy前一天的结果，卖了变0=上一次买入后的结果(在[1]) + 今日股票价格
        // 翻译：要抵达今天第i日，还可交易k次，手里无票的状态，
        //      要么本来就无票什么也做不了，收益和昨天一致
        //      要么今天有票打算卖掉变成无票，上次买入后的收益储存在[i-1][k][1]，再加上prices[i]便是
        // // 注意是dp[i-1][k][1]！！！已经有股票但还没卖掉，那还是“本次交易"而不是”上次交易“！
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
        // 翻译：要抵达今天第i日，还可交易k次，手里无票的状态，
        //      要么本来就无票什么也做不了，收益和昨天一致
        //      要么今天有票打算卖掉变成无票，上次买入后的收益储存在[i-1][k][1]，再加上prices[i]便是
        // 注意是dp[i-1][k-1][0]！！！上次我们卖掉了，交易是"上次交易"，不是我们现在正在进行的了，
        //    所以k-1表示只剩下k-1笔交易可以做，而不是k笔了！
            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

// 万法归一：
// 同时考虑交易次数的限制、冷冻期和手续费
int maxProfit_all_in_one(int max_k, int[] prices, int cooldown, int fee) {
    int n = prices.length;
    if (n <= 0) {
        return 0;
    }
    if (max_k > n / 2) {
        // 交易次数 k 没有限制的情况
        return maxProfit_k_inf(prices, cooldown, fee);
    }

    int[][][] dp = new int[n][max_k + 1][2];
    // k = 0 时的 base case
    for (int i = 0; i < n; i++) {
        dp[i][0][1] = Integer.MIN_VALUE;
        dp[i][0][0] = 0;
    }

    for (int i = 0; i < n; i++) 
        for (int k = max_k; k >= 1; k--) {
            if (i - 1 == -1) {
                // base case 1
                dp[i][k][0] = 0;
                dp[i][k][1] = -prices[i] - fee;
                continue;
            }

            // 包含 cooldown 的 base case
            if (i - cooldown - 1 < 0) {
                // base case 2
                dp[i][k][0] = Math.max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                // 别忘了减 fee
                dp[i][k][1] = Math.max(dp[i-1][k][1], -prices[i] - fee);
                continue;
            }
            dp[i][k][0] = Math.max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            // 同时考虑 cooldown 和 fee
            dp[i][k][1] = Math.max(dp[i-1][k][1], dp[i-cooldown-1][k-1][0] - prices[i] - fee);     
        }
    return dp[n - 1][max_k][0];
}

// k 无限制，包含手续费和冷冻期
int maxProfit_k_inf(int[] prices, int cooldown, int fee) {
    int n = prices.length;
    int[][] dp = new int[n][2];
    for (int i = 0; i < n; i++) {
        if (i - 1 == -1) {
            // base case 1
            dp[i][0] = 0;
            dp[i][1] = -prices[i] - fee;
            continue;
        }

        // 包含 cooldown 的 base case
        if (i - cooldown - 1 < 0) {
            // base case 2
            dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i]);
            // 别忘了减 fee
            dp[i][1] = Math.max(dp[i-1][1], -prices[i] - fee);
            continue;
        }
        dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        // 同时考虑 cooldown 和 fee
        dp[i][1] = Math.max(dp[i - 1][1], dp[i - cooldown - 1][0] - prices[i] - fee);
    }
    return dp[n - 1][0];
}

        
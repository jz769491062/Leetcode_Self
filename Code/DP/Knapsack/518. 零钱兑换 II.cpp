class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 注意dp 数组的转移只和 dp[i][..] 和 dp[i-1][..] 有关，可以压缩
        vector<int> dp(amount + 1);
        // 面额为0也有1种解法
        dp[0] = 1;
        // 注意现在外层只需要遍历coins而不是dp本身
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] >= 0) {
                    dp[j] = dp[j] + dp[j - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        // 定义：如果只使用coins的前i个的面值的话，凑出金额j有多少种解法。
        // 面额为0也有1种解法
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (j - coins[i - 1] >= 0) {
                    // 注意这里用相加，也就是利用之前无该硬币时的结果，再加上用掉这枚硬币后，然后还可以使用第i枚硬币的话，还有多少解法
                    // 注意之前的结果是dp[i - 1]，然后加上的是dp[i]本行的解法
                    // 相当于包含了重复使用的情况
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};// https://leetcode.cn/problems/coin-change-ii/description/
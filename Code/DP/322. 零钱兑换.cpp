class Solution {
public:
vector<int> dpArr;
    int DP(vector<int>& coins, int amount) {
        // base case: amount为0时返回0，不需要再凑了
        if (amount == 0) return 0;
        if (amount < 0) return -1; // 小于0说明没凑成，返回-1
        // 确认状态：面额是输入的，硬币数量也是无限的，每一个子问题变化的只有amount,
        // 所以amount就是状态

        // 确认选择：什么会导致状态变化？此题中，面值coins[]就是“选择”

        // 明确dp数组的含义，每一个数组里的元素代表了一个子问题。
        // 那么这里就是：已知当前amount为i，dp[i]存储amount为i时需要的最少硬币数量
        if (dpArr[amount] != -100000) return dpArr[amount]; //算过了，去掉重复子问题
        int res = INT_MAX;
        for (int c : coins) {
            int subProblem = DP(coins, amount - c);
            if (subProblem == -1) continue;
            res = min(res, 1 + subProblem);//注意+1!!!
            // 我们是不带这枚硬币，还是带上这枚硬币(+1)?
        }
        //算完了，存备忘录
        // 记得考虑没凑成的-1的情况,所有的面值都没凑成的话res就还是INT_MAX
        dpArr[amount] = (res == INT_MAX) ? -1 :res;
        return dpArr[amount]; //注意，不要return res了，return dpArr[amount]
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        dpArr = std::vector<int>(amount + 1, -100000);// +1是因为包含dp[amount]
        return DP(coins, amount);
    }
};//https://leetcode.cn/problems/coin-change/description/

//迭代解法：
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); //amount + 1是一个不可能的初始值
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            for (int c :coins) {
                if (i - c < 0) {// amount < 0
                    continue;
                }
                // dp数组是dp[amount] = coinnum
                dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        // dp[amount]没变，说明硬币匹配不到这个数字
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};//https://leetcode.cn/problems/gaM7Ch/submissions/392540466/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 背包定义dp[i][w]：对于前i个物品，当容量为w时，最大能装的价值是多少
        // 这个问题就是2个sum/2容量的背包，问是否正好能装满
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int capacity = sum / 2;
        // 注意到 dp[i][j] 都是通过上一行 dp[i-1][..] 转移过来的，之前数据不再使用
        // 那就压缩成1维
        vector<bool> dp(capacity + 1, false);
        // base case
        dp[0] = true;
        // 这个外层循环起到了尝试不同物品的作用
        for (int i = 0; i < nums.size(); i++) {
            for (int w = capacity; w >= 0; w--) {
                // 装不下的时候只是继承之前的结果,那其实我们只要在一维对应的索引保留之前状态即可，不用显式处理了
                // 装得下的时候更新状态，剩下的就看之前状态就行，没毛病
                if (w - nums[i] >= 0) {
                    dp[w] = dp[w] || dp[w - nums[i]];
                }
            }
        }
        return dp[capacity];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 背包定义dp[i][w]：对于前i个物品，当容量为w时，最大能装的价值是多少
        // 这个问题就是2个sum/2容量的背包，问是否正好能装满
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int capacity = sum / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(capacity + 1, false));
        // base case
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < dp.size(); i++) {
            for (int w = 1; w < dp[0].size(); w++) {
                if (w - nums[i - 1] < 0) {
                    // 装不下，只能继承结果
                    dp[i][w] = dp[i - 1][w];
                } else {
                    // 看看装入或者不装入有没有办法满足条件，也就是到达true的那行base case
                    // 这里用 || 相当于是择优了
                    dp[i][w] = dp[i - 1][w] || dp[i - 1][w - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][capacity];
    }
};
// https://leetcode.cn/problems/partition-equal-subset-sum/description/
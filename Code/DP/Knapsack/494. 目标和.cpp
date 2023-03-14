class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 也就是把原问题转化成：nums 中存在几个子集 A，使得 A 中元素的和为 (target + sum(nums)) / 2
        // 推导见 https://labuladong.gitee.io/algo/di-er-zhan-a01c6/bei-bao-le-34bd4/dong-tai-g-35341/
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum < abs(target) || (sum + target) % 2 == 1) {
            return 0;
        }
        int capacity = (sum + target) / 2;
        int n = nums.size();
        vector<int> dp(capacity + 1);
        // base case
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = capacity; j >= 0; j--) {
                // 二维压缩到一维的根本原理是，dp[j] 和 dp[j-nums[i-1]] 还没被新结果覆盖的时候，相当于二维 dp 中的 dp[i-1][j] 和 dp[i-1][j-nums[i-1]]
                // 所以在计算新的 dp[j] 的时候，dp[j] 和 dp[j-nums[i-1]] 需要还是上一轮外层 for 循环的结果
                // 所以倒着遍历j，保证dp[j-nums[i-1]]利用的是上一轮循环的结果
                if (j >= nums[i - 1]) {
                    dp[j] = dp[j] + dp[j - nums[i - 1]];
                }
            }
        }
        return dp[capacity];
    }
};// https://leetcode.cn/problems/target-sum/description/
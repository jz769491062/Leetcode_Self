class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 对于每一位数字，决定：是从这一位数字为头部开始计算，还是续接之前的结果？
        // 由于必须连续，所以一般的DP定义不行，需要是：
        // 以 nums[i] 为结尾的「最大子数组和」为 dp[i]
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};// https://leetcode.cn/problems/maximum-subarray/description/
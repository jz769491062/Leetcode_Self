class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //dp[i, j]: max result when we break ballons from i to j, exclusive
        // 正向思考就是回溯算法，但是时间复杂度是阶乘的；
        // 我们需要「反向思考」，想一想气球i和气球j之间最后一个被戳破的气球可能是哪一个
        // i和j就是两个「状态」，最后戳破的那个气球k就是「选择」
        // 那得先把开区间(i, k)的气球都戳破，再把开区间(k, j)的气球都戳破；
        // [i, , , , k, , , j]
        // 最后剩下的气球k，相邻的就是气球i和气球j，这时候戳破k的话得到的分数就是points[i]*points[k]*points[j]
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> val (n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <=n; i++) {
            val[i] = nums[i - 1];
        }
        // i prev, k curr, j next
        // 用到[i][k]和[k][j]，所以i < k < j，然后dp依赖左边和下边的格子
        // 所以需要j从左到右，i从下到上
        // i从n开始到0，j 从i + 1开始到n+1，是因为这是最后一个开区间[n , n + 1]的位置
        for (int i = n; i >=0 ; i--) {
            for (int j = i + 1; j < n + 2; j++) {
                // 最后戳破的气球是哪个？
                // 择优做选择，使得 dp[i][j] 最大
                // k从i + 1开始，是因为开区间，不要重复计算
                for (int k = i + 1; k < j; k++) {
                    int curr = val[i] * val[j] * val[k];
                    curr += dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], curr);
                }
            }
        }
        return dp[0][n + 1];
    }
};// https://leetcode.cn/problems/burst-balloons/description/
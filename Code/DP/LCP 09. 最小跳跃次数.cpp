class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        if (jump[0] >= n) {
            return 1;
        }
        vector<int> dp(n);
        dp[n - 1] = 1;
        for (int i = n - 2; i >=0; i--) {
            // 先算向右跳需要几次
            if (jump[i] + i >= n) {
                dp[i] = 1;
            } else {
                dp[i] = dp[jump[i] + i] + 1;
            }
            // dp[i]更新了，其后的数据会受到影响（向左回跳的情况）
            // 如果dp[j]跳跃次数本来就不比dp[i]大，那就不用更新了，已经当前最佳了，而且j之后的步数也不会更大，可以剪枝，保证不超时
            for (int j = i + 1; j < n && dp[j] > dp[i]; j++) {
                dp[j] = dp[i] + 1;
            }
        }
        return dp[0];
    }
};// https://leetcode.cn/problems/zui-xiao-tiao-yue-ci-shu/description/?company_slug=huawei
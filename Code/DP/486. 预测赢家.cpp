class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return stoneGame(nums) >= 0;
    }

    int stoneGame(vector<int>& nums) {
        int n = nums.size();
        // pair的first是先手最高分数，pair的second是后手最高分数
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
        // 状态：左索引，右索引(闭区间)，轮到谁了
        // 如何表达选择后对接下来游戏的影响?
        // base case: 只有一石头的时候，先手必得分
        for (int i = 0; i < n; i++) {
            dp[i][i].first = nums[i];
            dp[i][i].second = 0;
        }
        // 又是经典的从下到上、从左到右遍历，因为依赖左边和下边的结果
        // 不过需要注意怎么取max...
        // 如果选了left, 那么还剩下[left + 1, right]并且变成后手状态
        // 如果选了right，那么还剩下[left, right - 1]并且变成后手状态
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int left = nums[i] + dp[i + 1][j].second;
                int right = nums[j] + dp[i][j - 1].second;
                if (left > right) {
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i + 1][j].first;// 一开始后手，下一步就是先手
                } else {
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        }
        pair<int, int> res = dp[0][n - 1];
        return res.first - res.second;
    }
};// https://leetcode.cn/problems/predict-the-winner/description/ 和 877一样
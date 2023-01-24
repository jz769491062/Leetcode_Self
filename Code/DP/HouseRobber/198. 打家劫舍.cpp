// 第一步，明确状态和选择
// 状态：当前房子nums[i]
// 选择：抢或者不抢
// 不抢，跳转到下家；抢，跳转到下下家。
class Solution {
public:
// 存在重叠子问题：盗贼有多种办法抵达某一个房子。
vector<int> memo;
    int dp(vector<int>& nums, int start) {
        if (start >= nums.size()) return 0;
        // 用memo避免回头路
        if (memo[start] != -1) return memo[start];
        int res = max(dp(nums, start + 1), nums[start] + dp(nums, start + 2));
        memo[start] = res;// 已经保证走到这一步是当前的max结果了，所以直接放心赋值
        return res;
    }

    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return dp(nums, 0);
    }
};
//https://leetcode.cn/problems/house-robber/description/
class Solution {
public:
    int rob(vector<int>& nums) {
        // 循环解法：bottom-top
        // 由于我们的转移公式得知道下一间房子，下下间房子的数值，所以得倒着遍历
        vector<int> dp(nums.size() + 2, 0);//包含了dp[n], dp[n + 1] base case的初始化
        for (int i = nums.size() - 1; i >= 0; i--) {
            int res = max(dp[i + 1], dp[i + 2] + nums[i]);
            dp[i] = res;
        }
        return dp[0];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        // O(1)空间优化
        // 其实我们dp数组只需要一直保存2个数，抢和不抢的
        int rob = 0, notRob = 0, curr = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            curr = max(notRob, nums[i] + rob);
            rob = notRob;// 三个数，依次是curr, notRob, rob。更新的话就是往前推一格
            notRob = curr;
        }
        return curr;
    }
};
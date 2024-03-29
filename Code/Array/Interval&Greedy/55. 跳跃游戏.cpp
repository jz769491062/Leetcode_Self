class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        // 注意是n-1，只是到达最后一个下标而已
        for (int i = 0; i < n - 1; i++) {
            // 不断计算能跳到的最远距离
            farthest = max(farthest, i + nums[i]);
            // 可能碰到了 0，卡住跳不动了
            if (farthest <= i) {
                return false;
            }
        }
        return farthest >= n - 1;
    }
};// https://leetcode.cn/problems/jump-game/description/
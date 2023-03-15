class Solution {
public:
    int jump(vector<int>& nums) {
        // 可以动态规划做，不过我们真的有必要算出每一个子问题的解吗？
        // 站在当前格子，我们只需要选择可能跳到最远的那一条路即可，因为数字定义的是最大跳跃距离而不是固定跳跃距离
        int n = nums.size();
        int end = 0, farthest = 0;
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(i + nums[i], farthest);
            // 这样确保end一直在能跳到的最远的地方，更新时才更新jump数。毕竟题目已经保证可以抵达终点了
            if (i == end) {
                res++;
                end = farthest;
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/jump-game-ii/description/
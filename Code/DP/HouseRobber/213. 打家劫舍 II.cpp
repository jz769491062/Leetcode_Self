class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int rob = 0, notRob = 0, curr = 0;
        for (int i = end; i >= start; i--) {
            //      curr notRob Rob
            // curr notRob Rob
            // so Rob = notRob, notRob = curr
            curr = max(rob + nums[i], notRob);
            rob = notRob;
            notRob = curr;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        // 环形，首尾部分有几种可能？
        // 1 首尾都不抢 1 ~ n-2， 2 抢尾不抢首 1 ~ n-1， 3 抢首不抢尾 0 ~ n-2
        // 首尾都不抢，相当于只考虑1~n-2，也就是比情况2和情况3考虑的范围都小
        // 所以我们只用考虑情况2、3的结果然后比对即可
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robRange(nums, 1, n - 1), robRange(nums, 0, n - 2));
    }
};// https://leetcode.cn/problems/house-robber-ii/description/
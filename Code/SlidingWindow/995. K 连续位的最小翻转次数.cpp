class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // 模拟真实翻转会超时
        // 改用队列模拟窗口：前K-1个元素中，以哪些idx起始的区间进行了翻转。
        // 注意后面区间的翻转不影响前面的元素，所以才可以贪心从左到右每个0都把它和后面K-1个元素翻转
        // 队列元素的个数代表了i被前面K-1个元素翻转了多少次
        // 当 A[i] 为 0，如果 i 位置被翻转了偶数次，那么翻转后仍是 0，当前元素需要翻转
        // 当 A[i] 为 1，如果 i 位置被翻转了奇数次，那么翻转后变成 0，当前元素需要翻转
        // 所以len{queue} % 2 == nums[i]时，元素需要反转(以该元素开头的区间需要反转?)
        int n = nums.size();
        queue<int> q;
        int res = 0;
        for (int i = 0; i < n; i++) {
            // 前面的K位反转计算完了，可以Pop了
            if (!q.empty() && i >= q.front() + k) {
                q.pop();
            }
            // 该元素需要反转的情况
            if (q.size() % 2 == nums[i]) {
                // 如果剩余数字不够反转的了，说明做不到反转成全1
                if (i + k > n) {
                    return -1;
                }
                q.push(i);
                res++;
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips/description/
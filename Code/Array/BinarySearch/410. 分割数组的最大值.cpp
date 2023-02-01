class Solution {
public:
    bool canLower(vector<int>& nums, int maxSum, int k) {
        // 设mid为每个子数组最大的和，这样我们最少要分几组？
        // 如果组数超过k说明说明我们设定的最大值太低了，否则要么满足题意要么还可以找个更小的mid值
        int groups = 1;// 注意，至少分一组
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > maxSum) {
                groups++;
                sum = nums[i];//下一组直接以当前nums[i]作为第一个数
            } else {
                sum += nums[i];
            }
        }
        // 以当前的最大值，最少要分几组？大于k说明最大值设定的太低了，小于k说明最大值还可以压低
        return groups <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        // O(n×log⁡(sum−maxn))，其中 sum 表示数组 nums 中所有元素的和，maxn 表示数组所有元素的最大值
        // 确认搜索的上下界：至少是数组中最大的数字，至多则是数组中所有数字的和
        // 二分+贪心
        int left = 0, right = 0;
        for (int& num : nums) {
            right += num;
            if (num > left) {
                left = num;
            }
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 贪心：能否找到一个比mid还低的子数组和？
            if (canLower(nums, mid, k)) {
                right = mid;
            } else {
                left = mid +1;
            }
        }
        return left;
    }
};//https://leetcode.cn/problems/split-array-largest-sum/description/
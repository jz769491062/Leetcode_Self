class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // 找到一个nums[i] < nums[i + 1]的, i+1 ~ n 是降序的
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            // 倒序再找到第一个比nums[i]大的[j]
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            // 交换元素，大数去前面小数去后面
            swap(nums[i], nums[j]);
        }
        // 反转，i + 1到n区间的升序变成降序
        reverse(nums.begin() + i + 1, nums.end());
    }
};// https://leetcode.cn/problems/next-permutation/description/
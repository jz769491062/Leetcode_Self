// https://leetcode.cn/problems/4sum/
class Solution {
public:
    vector<vector<int>> nSumTarget(vector<int>& nums, long n, long start, long target) {
        int sz = nums.size();
        vector<vector<int>> res;
        // 至少是 2Sum，且数组大小不应该小于 n
        if (n < 2 || sz < n) return res;
        if (n == 2) {
            int lo = start, hi = sz - 1;
            while (lo < hi) {
                int left = nums[lo], right = nums[hi];
                long sum = left + right;// 注意，使用long防止int overflow
                if (sum < target) {
                    // 跳过重复的数字
                    while (lo < hi && nums[lo] == left) {
                        lo++;
                    }
                } else if (sum > target) {
                    // 跳过重复的数字
                    while (lo < hi && nums[hi] == right) {
                        hi--;
                    }
                } else if (sum == target){
                    res.push_back({left, right});
                    // 注意，这里还需要跳过重复的数字，保证一个答案只被添加一次
                    while (lo < hi && nums[lo] == left) {
                        lo++;
                    }
                    while (lo < hi && nums[hi] == right) {
                        hi--;
                    }
                }
            }
        } else {
            for (long i = start; i < sz; i++) {
                vector<vector<int>> subResult = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int>& sub : subResult) {
                    // (n-1)Sum 加上 nums[i] 就是 nSum
                    sub.push_back(nums[i]);
                    res.push_back(sub);// 每次递归都从空的res开始，所以不用担心会有额外的不完整的X元组
                }
                // 如果和当前数字，我们要找的3数中的第一个数重复，就跳过
                while (i < sz - 1 && nums[i] == nums[i + 1]) i++;
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 当然也可以参考15题，继续套娃，但这里还是写一个通用的nSum吧
        sort(nums.begin(), nums.end());
        // n 为 4，从 nums[0] 开始计算和为 target 的四元组
        return nSumTarget(nums, 4, 0, target);
    }
};
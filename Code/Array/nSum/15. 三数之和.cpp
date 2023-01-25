class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        // 排序双指针做法，方便扩展到nSum
        // sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int lo = start, hi = nums.size() - 1;
        while (lo < hi) {
            int left = nums[lo], right = nums[hi];
            int sum = left + right;
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
        return res;
    }
    // O(NlogN + N^2) = O(N^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int target = 0;
        int n = nums.size();
        // 穷举第一个数，剩下的找twoSum
        for (int i = 0; i < n; i++) {
            // 计算 target-nums[i]的2Sum，第一个数字
            vector<vector<int>> myPairs = twoSum (nums, i + 1, target - nums[i]);
            for (auto p: myPairs) {// 对于有答案的每一对，接上nums[i]，加进res
                p.push_back(nums[i]);
                res.push_back(p);
            }
            // 如果和当前数字，我们要找的3数中的第一个数重复，就跳过
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};// https://leetcode.cn/problems/3sum/description/
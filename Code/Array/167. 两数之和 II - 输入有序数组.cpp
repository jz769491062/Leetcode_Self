class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 双指针左右两头找
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left + 1, right + 1};
            else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {0, 0};
    }
};
//https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/
// https://leetcode.cn/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        // 只要不是目标元素，就按顺序移到前面去，把握住0~j的loop invariant
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
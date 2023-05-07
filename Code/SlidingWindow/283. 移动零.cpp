class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[slow] = nums[i];
                slow++;
            }
        }
        for (; slow < nums.size(); slow++) {
            nums[slow] = 0;
        }
    }
};// https://leetcode.cn/problems/move-zeroes/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i = 0, j = 0;
        int res = 0;
        while (j < nums.size()) {
            if (j > 0 && nums[j - 1] >= nums[j]) {
                i = j;
            }
            j++;
            res = max(res, j - i);
        }
        return res;
    }
};// https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
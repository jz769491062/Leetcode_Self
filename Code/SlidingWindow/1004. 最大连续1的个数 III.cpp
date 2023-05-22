class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int count = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                count++;
            }
            right++;
            while (count > k) {
                if (nums[left] == 0) {
                    count--;
                }
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};// https://leetcode.cn/problems/max-consecutive-ones-iii/solutions/608931/zui-da-lian-xu-1de-ge-shu-iii-by-leetcod-hw12/
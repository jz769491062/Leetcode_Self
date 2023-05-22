class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0;
        int res = 0;
        int lastEnd = 0;
        bool flipped = false;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                if (!flipped) {
                    flipped = true;
                } else {
                    res = max(res, right - left);
                    // 遇到第二个0，下次left以第一个0后面那个1作为开头，设第二个0已经转1
                    left = lastEnd + 1;
                }
                lastEnd = right;
            }
            right++;
        }
        res = max(res, right - left);
        return res;
    }
};// https://leetcode.cn/problems/max-consecutive-ones-ii/description/
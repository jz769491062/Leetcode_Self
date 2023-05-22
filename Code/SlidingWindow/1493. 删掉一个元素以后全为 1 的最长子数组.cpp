class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // 首先，子数组0的数量肯定不能超过1个
        // 既然可能删除1或者0，那么也可以说怎么样都要删除一个数字
        // 问题转化：窗口0的个数<=1, 的最长长度，再-1
        int res = 0;
        int left = 0;
        int right = 0;
        int cnt = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                cnt++;
            }
            right++;
            while (cnt > 1) {
                if (nums[left] == 0) {
                    cnt--;
                }
                left++;
            }
            res = max(res, right - left - 1);
        }
        return res;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //快慢双指针，慢的永不重复
        //直接顺序copy不重复的元素来实现原地操作
        int fast = 0;
        int slow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (fast >= nums.size()) {
                break;
            }
            if (nums[fast] == nums[slow]) {
                fast++;
            } else {
                slow++;
                nums[slow] = nums[fast];
                //注意，无论哪种情况fast都要前进的
                fast++;
            }
        }
        return slow + 1;
    }
};
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
//类似题目: https://leetcode.cn/problems/move-zeroes/description/ , https://leetcode.cn/problems/remove-element/
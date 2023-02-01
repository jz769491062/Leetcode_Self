class Solution {
public:

    //搜索有序数组中target最靠左的位置：
    int leftBound(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // <=是左右区间都闭合，所以搭配nums.size()-1,；<是左闭右开，所以搭配nums.size()
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid - 1;//注意！
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        // 注意！left = mid + 1可能导致left索引越界，比如target不存在而且数字很大的情况。
        // 所以这里需要额外判断left合法性
        if (left == nums.size()) return -1;
        // 另一种可能是target不存在而且数字很小，所以这里依然要判断nums[left]是否是target
        return nums[left] == target ? left : -1;
    }

    //搜索有序数组中target最靠右的位置：
    int rightBound(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;//注意！
            } else if (nums[mid] > target) {
                right = mid; // 左闭右开
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        // 注意，此时left在mid+1，mid+1不一定是target，而mid还是
        // 所以这里使用left - 1
        // 用right - 1也一样，因为循环终止条件是left == right
        if (left - 1 < 0) return -1;// 如果left没更新过的话，还是0，所以检查越界
        return nums[left - 1] == target ? (left - 1) : -1;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int first = leftBound(nums, target);
        int last = rightBound(nums, target);
        return {first, last};
    }
};// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
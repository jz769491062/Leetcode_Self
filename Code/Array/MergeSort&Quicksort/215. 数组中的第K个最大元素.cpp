// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
// 快速排序
class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi) {
        // 选数组第一个数当pivot
        int pivot = nums[lo];
        // pivotIndex指向左半边+pivot本身的边界索引
        int pivotIndex = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (nums[i] < pivot) {
                // 如果当前更小的数字紧挨着pivot，那只是更新pivotIndex，交换相当于没交换
                // 如果当前更小的数字和pivot隔着，那pivotIndex++就是更新到了一个比pivot更大的元素，然后交换
                // 因为nums[i] >= pivot时我们循环是什么也不做的，所以pivotIndex只在nums[i]<pivot的时候++就保证了合法性
                pivotIndex++;
                int temp = nums[i];
                nums[i] = nums[pivotIndex];
                nums[pivotIndex] = temp;
            }
        }
        // 现在知道在哪里分界了，nums[pivotIndex]腾位置挪到第一位去，然后nums[pivotIndex]更新为pivot，partition完成
        nums[lo] = nums[pivotIndex];
        nums[pivotIndex] = pivot;
        return pivotIndex;
    }

    int findKthLargest(vector<int>& nums, int k) {
        // 第k个最大的，就是升序排名倒数第k个
        int targetIndex = nums.size() - k;
        int lo = 0, hi = nums.size() - 1;
        int index = partition(nums, lo, hi);
        // 等partition到了targetIndex就说明找到了
        // 快排是前序的，所以能在子问题中不断缩小targetIndex可能范围，最终找到
        while (index != targetIndex) {
            if (index > targetIndex) {
                hi = index - 1;
            } else {
                lo = index + 1;
            }
            index = partition(nums, lo, hi);
        }
        return nums[index];
    }
};
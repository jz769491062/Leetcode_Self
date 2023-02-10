class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi) {
        // 随机选个pivot，然后把pivot换到最前面以定位pivotIndex
        int randIndex = rand() % (hi - lo + 1) + lo;
        int pivot = nums[randIndex];
        swap(nums[randIndex], nums[lo]);
        // 单路排序，面对超多重复元素会超时
        // int pivotIndex = lo;
        // int temp = 0;
        // for (int i = lo + 1; i <= hi; i++) {
        //     if (nums[i] < pivot) {
        //         pivotIndex++;
        //         temp = nums[pivotIndex];
        //         nums[pivotIndex] = nums[i];
        //         nums[i] = temp;
        //     }
        // }
        // 需要双路排序、三路排序
        int i = lo + 1;
        int j = hi;
        while (true) {
            // 前后找，找到需要交换pivot左右区间的元素为止
            while (i <= hi && nums[i] < pivot) {
                i++;
            }
            while (j >= lo && nums[j] > pivot) {
                j--;
            }
            if (i >= j) break;//区间缩小到1了，没得找了
            swap(nums[i], nums[j]);
            // 解决大量重复元素的关键：每个循环会两侧收缩区间到中间，
            // 确保面对重复元素也能收缩搜索区间到一半，而不是劣化成n^2
            i++;
            j--;
        }
        int pivotIndex = j;
        nums[lo] = nums[pivotIndex];
        nums[pivotIndex] = pivot;
        return pivotIndex;
    }

    void qSort(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return;
        int index = partition(nums, lo, hi);
        // 注意这里递归qSort啊，不能在这递归partition
        qSort(nums, lo, index - 1);
        qSort(nums, index + 1, hi);
    }

    vector<int> sortArray(vector<int>& nums) {
        qSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};// https://leetcode.cn/problems/sort-an-array/description/
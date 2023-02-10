class Solution {
public:
// 用long防止int overflow
vector<long> tempVec; // 辅助merge数组用，因为不能直接原地比较+merge
int count = 0; // 多少区间和满足条件

    void merge(vector<long>& nums, int start, int mid, int finish, int lower, int upper) {
        for (int i = start; i <= finish; i++) {
            tempVec[i] = nums[i];// 复制一份用于比较
        }
        // 和493的区别:维护2个指针，滑动窗口，一边排除一边加入，一直保证[begin, end)区间满足题目要求
        // 这也是利用了左半边和右半边元素是“分开的”这一特性，这样只找半边也避免了重复计算的可能性
        // 注意此处的nums是前缀和数组，不是原来的那个输入的Nums
        int startIdx = mid + 1, endIdx = mid + 1;// 用end - start就是
        for (int i = start; i <=mid; i++) {
            // 如果 nums[i] 对应的区间是 [start, end)，
            // 那么 nums[i+1] 对应的区间一定会整体右移，类似滑动窗口
            // 每一个前缀和里的元素，都代表了一个区间的和。那窗口的大小就是满足要求的区间和的个数了
            while(startIdx <= finish && nums[startIdx] - nums[i] < lower) {
                startIdx++; // 缩小窗口
            }
            while (endIdx <= finish && nums[endIdx] - nums[i] <= upper) {
                endIdx++; // 扩大窗口
            }
            // 注意保证初始窗口是空的
            // cout << endIdx << " " <<startIdx <<endl;
            count += endIdx - startIdx;
        }

        // 双指针合并数组
        int leftHalfIdx = start, rightHalfIdx = mid + 1;
        for (int i = start; i <= finish; i++) {
            if (leftHalfIdx == mid + 1) {
                nums[i] = tempVec[rightHalfIdx];
                rightHalfIdx++;
            }
            else if (rightHalfIdx == finish + 1) {
                nums[i] = tempVec[leftHalfIdx];
                leftHalfIdx++;
            }
            // 比大小。注意在这里break tie!!!
            else if (tempVec[leftHalfIdx] <= tempVec[rightHalfIdx]) {
                nums[i] = tempVec[leftHalfIdx];
                leftHalfIdx++;
            }
            else {
                nums[i] = tempVec[rightHalfIdx];
                rightHalfIdx++;
            }
        }
    }

    void mSort(vector<long>& nums, int start, int finish, int lower, int upper) {
        if (start == finish) return;
        int mid = start + (finish - start) / 2;
        mSort(nums, start, mid, lower, upper);
        mSort(nums, mid + 1, finish, lower, upper);
        // 可以理解为二叉树后序
        merge(nums, start, mid, finish, lower, upper);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // 区间和，那需要前缀和数组辅助了
        // count[i] = COUNT(j) where lower <= preSum[j] - preSum[i] <= upper
        // 然后对前缀和数组进行归并排序，对于每一个要merge的子数组查找在题目规定区间的区间和有多少个
        // 也是因为merge的左半边和右半边都没有交集
        // 这样思路一转化，就和493 翻转对比较像了
        int n = nums.size();
        vector<long> preSum(n + 1);//防止int overflow
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + (long)nums[i];
        }
        // 注意传入的是preSum数组！
        tempVec.resize(n + 1);
        mSort(preSum, 0, n, lower, upper);
        return count;
    }
};// https://leetcode.cn/problems/count-of-range-sum/description/
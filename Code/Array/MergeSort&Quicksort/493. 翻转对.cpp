class Solution {
public:
vector<int> tempVec; // 辅助merge数组用，因为不能直接原地比较+merge
int count = 0; // 多少翻转对
    void merge(vector<int>& nums, int start, int mid, int finish) {
        for (int i = start; i <= finish; i++) {
            tempVec[i] = nums[i];// 复制一份用于比较
        }
        // 区别:每次merge前，对于左半边的每个数字，找右半边满足翻转对条件的数字有多少个
        // 这也是利用了左半边和右半边元素是“分开的”这一特性，这样只找半边也避免了重复计算翻转对的可能性
        int endIdx = mid + 1;// 用这个减去(mid + 1)就是翻转对的数量了
        for (int i = start; i <=mid; i++) {
            // 进行效率优化，维护左闭右开区间 [mid+1, end) 中的元素乘 2 小于 nums[i]
            // 为什么 end 是开区间？因为这样的话可以保证初始区间 [mid+1, mid+1) 是一个空区间
            while (endIdx <= finish && (long)nums[i] > ((long)nums[endIdx] * 2)) {
                endIdx++;
            }
            // cout << nums[i]  <<" " << nums[endIdx] <<endl;
            count += endIdx - (mid + 1);
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

    void mSort(vector<int>& nums, int start, int finish) {
        if (start == finish) return;
        int mid = start + (finish - start) / 2;
        mSort(nums, start, mid);
        mSort(nums, mid + 1, finish);
        // 可以理解为二叉树后序
        merge(nums, start, mid, finish);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size(); // 防止unsigned int underflow
        tempVec.resize(n);
        mSort(nums, 0, n - 1);
        return count;
    }
};
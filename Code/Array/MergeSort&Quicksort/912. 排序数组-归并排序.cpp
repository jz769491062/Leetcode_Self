class Solution {
public:
vector<int> tempVec; // 辅助merge数组用，因为不能直接原地比较+merge
    void merge(vector<int>& nums, int start, int mid, int finish) {
        for (int i = start; i <= finish; i++) {
            tempVec[i] = nums[i];// 复制一份用于比较
        }
        // 双指针合并数组
        int leftHalfIdx = start, rightHalfIdx = mid + 1;
        for (int i = start; i <= finish; i++) {
            // 注意temp保存的是原来的数组次序，比较的时候用temp，只是对Nums进行改变
            // 注意以下if条件不能合并，一定要先判断是不是半边数据都排入了，然后再比大小！
            // 如果左半边数据全都排入Nums，或者当前指针右半边数字更小，就把右半边指针元素排进去，指针前进
            if (leftHalfIdx == mid + 1) {
                nums[i] = tempVec[rightHalfIdx];
                rightHalfIdx++;
            }
            //注意要else if，一次循环只挪动一次指针
            // 如果右半边排完了，就一直挪动左指针
            else if (rightHalfIdx == finish + 1) {
                nums[i] = tempVec[leftHalfIdx];
                leftHalfIdx++;
            }
            // 比大小
            else if (tempVec[leftHalfIdx] <= tempVec[rightHalfIdx]) {
                nums[i] = tempVec[leftHalfIdx];
                leftHalfIdx++;
            }
            else { // 比大小的时候记得break tie, 一边是< 另一边就是 >=
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

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();// 防止unsigned int underflow
        tempVec.resize(n);
        mSort(nums, 0, n - 1);
        return nums;
    }
};//https://leetcode.cn/problems/sort-an-array/description/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // 元素和索引是成对儿出现的，常用的方法是排序、异或、映射
        int n = nums.size();
        int dup = -1; 
        for (int i = 0; i < n; i++) {
            // 现在的元素是从 1 开始的
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                dup = abs(nums[i]);
            else
                // 把数字变成负数，标记已经映射过了
                nums[index] *= -1;
        }

        int missing = -1;
        for (int i = 0; i < n; i++)
            // 没映射过的，就是缺的数字了
            if (nums[i] > 0)
                // 将索引转换成元素
                missing = i + 1;

        return {dup, missing};
    }
};// https://leetcode.cn/problems/set-mismatch/description/
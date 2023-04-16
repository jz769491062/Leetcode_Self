class Solution {// O(k*2^n) 以每个桶为视角进行计算，效率最高
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % k != 0) return false; // 剪枝，如果不能整除就可直接判false
        int used = 0;// 注意因为nums最多16个数，可以直接位操作表示used
        int target = sum / k;
        return backtrack(k, 0, nums, 0, used, target);
    }

    unordered_map<int, bool> pathMemo;// 路径-》是否使用过

    bool backtrack(int k, int currBucketSum, vector<int>& nums, int start, int used, int target) {
        if (k == 0) return true; // 桶装满且Nums用完，true
        if (currBucketSum == target) {
            // 当前桶装满了，开始下个桶
            bool res = backtrack(k - 1, 0, nums, 0, used, target);
            // 缓存
            pathMemo[used] = res;
            return res;
        }
        if (pathMemo.count(used)) return pathMemo[used];//剪枝重复路径
        for (int i = start; i < nums.size(); i++) {
            // 判断当前数字是否已经被使用过
            if (((used >> i) & 1) == 1) continue;
            if (nums[i] + currBucketSum > target) continue;//如果加入会超过target，跳过这个数字
            // 做选择
            // 置位used
            used |= 1 << i;
            currBucketSum += nums[i];
            if (backtrack(k, currBucketSum, nums, i + 1, used, target)) {
                return true; // 找到一种划分方法即可返回
            }
            //撤销
            currBucketSum -= nums[i];
            used ^= 1 << i; // 利用异或 重新设置0
        }
        return false; // 都遍历完了还没找到办法，false
    }
};// https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/description/
class Solution {// https://leetcode.cn/problems/random-pick-index/
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        // 同水塘抽样算法，但是这次只对于target进行水塘抽样，确保同数字每个索引返回概率相等
        int count = 0, res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) {
                continue;
            }
            count++;
            // 1/count的几率，每个索引被抽中概率相等
            if (rand() % count == 0) {
                res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
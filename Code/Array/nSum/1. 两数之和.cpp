class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 要返回下标，所以不能用排序双指针，不然顺序乱
        unordered_map<int, int> idxMap; // val -> index
        for (int i = 0; i < nums.size(); i++) {
            auto it = idxMap.find(target - nums[i]);
            if (it == idxMap.end()) {
                idxMap[nums[i]] = i;
            } else {
                return {it->second, i};
            }
        }
        return {};
    }
};// https://leetcode.cn/problems/two-sum/description/
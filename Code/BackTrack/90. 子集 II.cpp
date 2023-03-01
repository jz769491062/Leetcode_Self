class Solution {
public:
vector<vector<int>> res;
    void backtrack(vector<int>& curr, vector<int>& nums, int start) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            // 剪枝逻辑，值相同的相邻树枝，只遍历第一条
            if (i > start && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            backtrack(curr, nums, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());//配合剪枝用
        backtrack(curr, nums, 0);
        return res;
    }
};// https://leetcode.cn/problems/subsets-ii/description/
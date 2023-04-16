class Solution {
public:
// 如果不使用used数组，进入分支后分支会认为所有数字依然都能选，导致元素重复选择，错误。
// 比如[0,1]，如果不用used数组，还会输出[0,0], [1,1]错误答案
vector<bool> used;
vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& curr) {
        // 这里只检查size意味着剪枝要在下面for loop进行
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums,curr);
            used[i] = false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        used.resize(nums.size()); //记得初始化used数组大小
        backtrack(nums, curr);
        return res;
    }
};//https://leetcode.cn/problems/permutations/description/
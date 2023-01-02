class Solution {
public:
vector<bool> used;
vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& currVec) {
        if (currVec.size() == nums.size()) {
            result.push_back(currVec);
            return;
        }
        for (int a = 0; a < nums.size(); a++) {
            if (used[a]) continue;
            currVec.push_back(nums[a]);
            used[a] = true;
            backtrack(nums, used, currVec);
            used[a] = false;
            currVec.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size());
        vector<int> currVec;
        backtrack(nums, used, currVec);
        return result;
    }
};//https://leetcode.cn/problems/permutations/description/
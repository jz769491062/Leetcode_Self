class Solution {
public:
vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr) {
        int currSum = std::accumulate(curr.begin(), curr.end(), 0);
        if (currSum == target) {
            res.push_back(curr);
            return;
        }
        if (currSum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            // 如果此处用start而不是i，那就是每一个正确答案的所有排列也生成了，多余了
            backtrack(candidates, target, i, curr);// i+1避免复选元素，那用i就是允许同元素被重复选取了
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, target, 0, curr);
        return res;
    }
};//https://leetcode.cn/problems/combination-sum/description/
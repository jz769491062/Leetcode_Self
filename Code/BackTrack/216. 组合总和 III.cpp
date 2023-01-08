class Solution {
public:
vector<vector<int>> res;
    void backtrack(int k, int n, vector<int>& curr, int start) {
        int currSum = accumulate(curr.begin(), curr.end(), 0);
        if (curr.size() == k) {
            if (currSum == n) {// k个数，且和为n再push
                res.push_back(curr);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            backtrack(k, n, curr, i + 1); //元素不重复
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(k, n, curr, 1);
        return res;
    }
};//https://leetcode.cn/problems/combination-sum-iii/description/
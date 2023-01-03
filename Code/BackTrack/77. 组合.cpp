class Solution {
public:
vector<vector<int>> res;
    void backtrack(int n, vector<int>& currRes, int start, int k) {
        // 组合和子集的区别就是，组合pushback是有条件的
        if (currRes.size() == k) {
            res.push_back(currRes);
            return;
        }
        //使用start和+1，排除自身元素确保不重复
        for (int i = start; i <= n; i++) {// 注意遍历[1,n]，不是k
            currRes.push_back(i);
            backtrack(n, currRes, i + 1, k);
            currRes.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> currRes;
        backtrack(n, currRes, 1, k);
        return res;
    }
};//https://leetcode.cn/problems/combinations/description/
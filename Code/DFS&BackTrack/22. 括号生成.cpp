class Solution { // 4^n / sqrt(n) 指数级 卡特兰数
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string currStr;
        backtrack(res, n, 0, 0, currStr);
        return res;
    }

    void backtrack(vector<string> &res, int n, int leftCnt, int rightCnt, string &currStr)
    {
        // 对于每一个子串，左括号数量必须大于等于右括号数量
        if (leftCnt < rightCnt) return;
        if (leftCnt > n || rightCnt > n) return; // 不能超过n个括号
        if (leftCnt == n && rightCnt == n) { // 正好，那就是答案了
            res.push_back(currStr);
            return;
        }

        currStr.push_back('(');
        backtrack(res, n, leftCnt + 1, rightCnt, currStr);
        currStr.pop_back();

        currStr.push_back(')');
        backtrack(res, n, leftCnt, rightCnt + 1, currStr);
        currStr.pop_back();
    }
};// https://leetcode.cn/problems/generate-parentheses/description/
class Solution {// https://leetcode.cn/problems/different-ways-to-add-parentheses/description/
    unordered_map<string, vector<int>> memo;
public:
    vector<int> diffWaysToCompute(string expression) {
        // 对于分治问题，原问题结果应该可以通过合并子问题结果来计算
        // 1、不要思考整体，而是把目光聚焦局部，只看一个运算符。
        // 2、明确递归函数的定义是什么，相信并且利用好函数的定义。
        // 备忘录，同一个expression不必重复计算
        auto it = memo.find(expression);
        if (it != memo.end()) {
            return it->second;
        }
        vector<int> res;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == '-' || c == '+' || c == '*') {
                // 以运算符为界限，不断切分结果
                // for loop 从头循环到尾保证每一种情况都会处理到
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int a : left) {
                    for (int b : right) {
                        if (c == '-') {
                            res.push_back(a - b);
                        }
                        else if (c == '+') {
                            res.push_back(a + b);
                        }
                        else if (c == '*') {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }
        // 纯粹是数字,没有运算符的情况
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        memo[expression] = res;
        return res;
    }
};
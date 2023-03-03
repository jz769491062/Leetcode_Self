class Solution {
public:
    bool isValid(string s) {
        map<char, char> parenMap;
        parenMap[')'] = '(';
        parenMap[']'] = '[';
        parenMap['}'] = '{';
        stack<char> left;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                left.push(c);
            } else {
                if (!left.empty() && parenMap[c] == left.top()) {
                    left.pop();
                } else {
                    return false;
                }
            }
        }
        // 检查左括号是不是没有多余的
        return left.empty();
    }
};// https://leetcode.cn/problems/valid-parentheses/description/
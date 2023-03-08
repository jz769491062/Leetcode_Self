class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char sign = '+'; // 第一个数字前面自带加号
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = 10 * num + (c - '0');
            }
            // 注意条件，是运算符或者最后一位都要push了
            // 要在这里检查空格而不是提前，因为空格也可能出现在末尾
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                switch(sign) {
                    int pre;
                    case '+':
                        stk.push(num);
                        break;
                    case '-':
                        stk.push(-num);
                        break;
                    case '*':
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre * num);
                        break;
                    case '/':
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre / num);
                        break;
                }
                // 之后立刻更新sign，重置num
                sign = c;
                num = 0;
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};// https://leetcode.cn/problems/basic-calculator-ii/description/
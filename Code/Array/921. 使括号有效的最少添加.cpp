class Solution {
public:
    int minAddToMakeValid(string s) {
        int needRight = 0, needLeft = 0;
        for (char c : s) {
            if (c == '(') needRight++;
            if (c == ')') {
                needRight--;
                if (needRight == -1) {
                    needRight = 0;
                    needLeft++;
                }
            }
        }
        return needLeft + needRight;
    }
};// https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/
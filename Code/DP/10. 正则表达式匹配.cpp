class Solution {
    vector<vector<int>> memo;
public:
    bool isMatch(string s, string p) {
        memo.resize(s.size(), vector<int>(p.size(), -1));
        return DP(s, p, 0, 0);
    }

    bool DP(string& s, string& p, int i, int j) {
        int m = s.size(), n = p.size();
        // base case
        if (j == n) {
            // s字符串匹配完了吗?
            return i == m;
        }
        if (i == m) {
            if ((n - j) % 2 == 1) {
                return false; // 还剩奇数字符，无论有没有*都是匹配不上的
            }
            for (; j + 1 < n; j += 2) {
                if (p[j + 1] != '*') {
                    return false;// 还有剩余非*字符没匹配到，false
                }
            }
            return true;
        }
        // 注意先base case再调用memo
        if (memo[i][j] != -1) {
            return (bool)memo[i][j];
        }
        bool matchSingle = p[j] == '.' || p[j] == s[i];
        bool res = false;
        // * case, 不是最后一位且是*的话
        if (j <= p.size() - 2 && p[j + 1] == '*') {
            // 匹配多个s的字符的情况，或者是0个字符
            res = (matchSingle && DP(s, p, i + 1, j)) || DP(s, p, i, j + 2);
        } else {
            // 这一位匹配上了的话，也看下一位是否匹配上了
            res = matchSingle && DP(s, p, i + 1, j + 1);
        }
        memo[i][j] = res;
        return res;
    }
};// https://leetcode.cn/problems/regular-expression-matching/description/
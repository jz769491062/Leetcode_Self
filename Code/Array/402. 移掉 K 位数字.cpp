class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        // 删除数字的策略：如果前一个数字更大，那应该删除前面那个数字；如果字符串本身就是单调不减的，删除末尾即可。
        stack<char> stk;
        for (int i = 0; i < num.size(); i++) {
            while (!stk.empty() && stk.top() > num[i] && k > 0) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        // 字符串有单调不减的部分，剩下的位数要删除末尾
        while (k > 0) {
            res.pop_back();
            k--;
        }
        bool leadingZero = true;
        string ans;
        for (char c : res) {
            if (leadingZero && c == '0') {
                continue;
            }
            leadingZero = false;
            ans += c;
        }
        return ans == "" ? "0" : ans;
    }
};// https://leetcode.cn/problems/remove-k-digits/description/?company_slug=huawei
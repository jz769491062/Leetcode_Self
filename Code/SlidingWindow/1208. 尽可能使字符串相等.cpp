class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int right = 0;
        int res = 0;
        int cost = 0;
        while (right < s.size()) {
            cost += abs(s[right] - t[right]);
            right++;
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};// https://leetcode.cn/problems/get-equal-substrings-within-budget/description/
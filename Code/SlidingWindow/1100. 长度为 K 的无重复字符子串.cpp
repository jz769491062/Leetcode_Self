class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if (k > n) {
            return 0;
        }
        map<char, int> window;
        int res = 0;
        for (int i = 0; i < k; i++) {
            window[s[i]]++;
        }
        if (window.size() == k) {
            res++; //正好都不重复
        }
        // 新思路：维护map的size
        for (int i = k; i < s.size(); i++) {
            window[s[i]]++;
            window[s[i - k]]--;
            // 注意erase, 确保map的size一直反映无重复字符的数量
            if (window[s[i - k]] == 0) {
                window.erase(s[i - k]);
            }
            if (window.size() == k) {
                res++;
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters/description/
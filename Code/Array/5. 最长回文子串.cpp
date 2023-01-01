class Solution {
public:
    string findPalindrome(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // 此时出了循环，left和right是落在界外或者两char不等的index上的
        // 所以left要+1，回文长度是right- 1 - left
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        //双指针从中心向两端
        //奇数长度有1中心字符，偶数长度2个。
        //最长回文不一定从中间开始，所以以每一个index作为起点开始查找
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            string s1 = findPalindrome(s, i, i);//奇数情况
            string s2 = findPalindrome(s, i, i + 1);//偶数情况
            res = res.size() < s1.size() ? s1 : res;
            res = res.size() < s2.size() ? s2 : res;
        }
        return res;
    }
};//https://leetcode.cn/problems/longest-palindromic-substring/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int res = 0;
        map<char, int> myMap;
        while (right < n) {
            char c = s[right];
            myMap[c]++;// 注意顺序，先访问s[right]再更新right
            right++;
            // 有重复字符了，开始缩小窗口
            while (myMap[c] > 1) {
                myMap[s[left]]--;// 注意顺序，先访问s[left]再更新left
                left++;
            }
            // 此时是当前的无重复最长子串，更新
            res = max(res, right - left);
        }
        return res;
    }
};// https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
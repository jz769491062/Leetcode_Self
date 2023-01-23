class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;
        int left = 0, right = 0, valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++; // 注意顺序！
                if (window[c] == need[c]) {// 只在字符出现次数一致时增加valid
                    valid++;
                }
            }
            while (right - left >= s1.size()) {//缩小到比s1长度还短，以继续查找s2剩余的
                // 出现次数都一样，那就是找到了一个排列
                if (valid == need.size()) return true;
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {// 只在字符出现次数一致时减少valid
                        valid--;
                    }
                    window[d]--; // 注意顺序！
                }
            }
        }
        return false;
    }
};// https://leetcode.cn/problems/permutation-in-string/description/
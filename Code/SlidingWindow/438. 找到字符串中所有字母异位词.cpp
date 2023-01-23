class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 相当于找到所有排列，并保存起始索引，和567一样
        vector<int> res;
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;
        int left = 0, right = 0, valid = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++; // 注意顺序！
                if (window[c] == need[c]) {// 只在字符出现次数一致时增加valid
                    valid++;
                }
            }
            while (right - left >= p.size()) {//缩小到比s1长度还短，以继续查找s2剩余的
                // 出现次数都一样，那就是找到了一个排列
                if (valid == need.size()) res.push_back(left);
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {// 只在字符出现次数一致时减少valid
                        valid--;
                    }
                    window[d]--; // 注意顺序！
                }
            }
        }
        return res;
    }
};//https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
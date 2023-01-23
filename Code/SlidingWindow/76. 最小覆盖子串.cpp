class Solution {
    public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;

        while (right < s.size()) {
            // c 是将移入窗口的字符
            char c = s[right];
            // 右移窗口
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {//在窗口内我们只关心t的字符们
                window[c]++;
                if (window[c] == need[c])//是否有一个字母已经在数量上完成匹配
                    valid++;
            }

            // 现在有合法的无重复子串，判断左侧窗口是否要收缩
            // 求最小覆盖子串，所以我们收缩到子串不合法为止，这样允许我们继续找新的s中字符进行匹配
            while (valid == need.size()) {

                // 在这里更新最小覆盖子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d 是将移出窗口的字符，注意顺序
                char d = s[left];
                // 左移窗口
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])//移出了一个t中的字符则更新valid
                        valid--;
                    window[d]--;
                    //现在字符串再次不合法了，继续匹配下去
                }
            }

        }
        // 返回最小覆盖子串
        return len == INT_MAX ?
                "" : s.substr(start, len);
    }
};
// https://leetcode.cn/problems/minimum-window-substring/description/
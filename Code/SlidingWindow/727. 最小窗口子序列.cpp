// https://leetcode.cn/problems/minimum-window-subsequence/description/
class Solution {
public:
    string minWindow(string s1, string s2) {
        // 最小子序列，正向收缩找最小边界是难判断的。
        // 所以逆向查找边界，舍弃更靠前的字符
        int i = 0, j = 0;
        int minLen = INT_MAX;
        string res = "";
        while (i < s1.size()) {
            if (s1[i] == s2[j]) {
                j++;
            }
            i++;
            // 匹配完了
            if (j == s2.size()) {
                // 逆向查找边界，找到再次不符合边界为止
                int rights2 = j - 1;
                int rights1 = i - 1;
                while (rights2 >= 0) {
                    if (s1[rights1] == s2[rights2]) {
                        rights2--;
                    }
                    rights1--;
                }
                int len = i - rights1 - 1;
                if (minLen > len) {
                    minLen = len;
                    res = string(s1.begin() + rights1 + 1, s1.begin() + i);
                }
                // 重置条件准备接下来的搜索
                j = 0;
                i = rights1 + 2;
            }
        }
        return res;
    }
};
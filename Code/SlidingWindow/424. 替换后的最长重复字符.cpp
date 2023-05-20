// https://leetcode.cn/problems/longest-repeating-character-replacement/description/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        if (len < 2) {
            return len;
        }

        int left = 0;
        int right = 0;

        int res = 0;
        int maxCount = 0;
        vector<int> freq(26, 0);
        // [left, right) 内最多替换 k 个字符可以得到只有一种字符的子串
        while (right < len){
            freq[s[right] - 'A']++;
            // 在这里维护 maxCount，因为每一次右边界读入一个字符，字符频数增加，才会使得 maxCount 增加
            maxCount = max(maxCount, freq[s[right] - 'A']);
            right++;

            if (right - left > maxCount + k){
              	// 说明此时 k 不够用
                // 把其它不是最多出现的字符替换以后，都不能填满这个滑动的窗口，这个时候须要考虑左边界向右移动
                // 移出滑动窗口的时候，频数数组须要相应地做减法
                freq[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
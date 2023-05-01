class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // 出现奇数次的字母记录下来，根据奇数次字幕出现次数再进行操作
        // 如果字符串长度为奇数，则最少需要将(odd−1)/2(odd-1)/2(odd−1)/2个字符进行替换，如果字符串长度为偶数，则最少需要将odd/2odd/2odd/2个字符进行替换。
        //  先看清题目：子串是允许重新排列顺序的。。。
        // 字符串s前i个字符中字符 'a'+j (0 <= j < 26)出现的次数，最后在区间 [l,r] 中可通过 pre[r+1][j]-pre[l][j] 来得到某个区间内某字符的出现次数
        int pre[100005][26];
        memset(pre,0,sizeof(pre));
        for (int i = 1; i <= s.size(); i++) {
            pre[i][s[i - 1] - 'a']++;
            for (int j = 0; j < 26; j++) {
                pre[i][j] += pre[i - 1][j]; // 是前缀和，所以记得继承之前算过的char数量
            }
        }
        int odd = 0;
        vector<bool> ans;
        for (vector<int>& q : queries) {
            odd = 0;
            for (int i = 0; i < 26; i++) {
                odd += (pre[q[1] + 1][i] - pre[q[0]][i]) % 2; // 字符出现奇数次则++
            }
            odd /= 2;
            ans.emplace_back(odd <= q[2]); // <=说明可以替换
        }
        return ans;
    }
};

// https://leetcode.cn/problems/can-make-palindrome-from-substring/solutions/1004929/
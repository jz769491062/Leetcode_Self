// https://leetcode.cn/problems/reverse-words-in-a-string/
// 常规思路是split, reverse单次顺序再join，其实太复杂了
// 技巧：先reverse整个句子，然后reverse每个单词，搞定
// 计算机觉得优雅的思维，对我们来说可能不直观，反之亦然
class Solution {
public:
    string reverseWords(string s) {
        // 新思路：反转整个句子，然后对每个单词反转
        reverse(s.begin(), s.end());
        string res;
        istringstream iss(s);
        while(iss) {
            string t;
            iss >> t;
            // 反转每个单词
            reverse(t.begin(), t.end());
            res += t;
            res += " ";
        }
        return res.substr(0, res.size() - 2);
    }
};
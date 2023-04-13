class Solution {
    vector<string> res;
public:
    vector<string> letterCasePermutation(string s) {
        string path;
        backtrack(s, path, 0);
        return res;
    }

    void backtrack(string& s, string& path, int index) {
        int n = s.size();
        while (index < n && isdigit(s[index])) {
            index++;
        }
        if (index == n) {
            res.push_back(s);
            return;
        }
        s[index] ^= 32;
        backtrack(s, path, index + 1);
        s[index] ^= 32;
        backtrack(s, path, index + 1);
    }
};// https://leetcode.cn/problems/letter-case-permutation/description/
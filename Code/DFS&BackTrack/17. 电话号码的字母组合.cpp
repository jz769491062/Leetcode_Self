class Solution {
    vector<string> res;
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string path;
        backtrack(path, digits, 0);
        return res;
    }

    void backtrack(string& path, string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(path);
            return;
        }
        char digit = digits[index];
        for (char c : phoneMap[digit]) {
            path.push_back(c);
            backtrack(path, digits, index + 1);
            path.pop_back();
        }
    }
};// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
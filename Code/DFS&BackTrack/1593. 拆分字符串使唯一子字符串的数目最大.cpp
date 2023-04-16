class Solution {
    unordered_set<string> used;
    int res = 0;
    int stringCount = 0;
public:
    int maxUniqueSplit(string s) {
        backtrack(s, used, 0);
        return res;
    }

    void backtrack(string& s, unordered_set<string>& used, int start) {
        if (start == s.size()) {
            res = max(res, stringCount);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            string sub = s.substr(start, i - start + 1);
            if (!used.count(sub)) {
                stringCount++;
                used.insert(sub);
                backtrack(s, used, i + 1);
                used.erase(sub);
                stringCount--;
            }
        }
    }
};// https://leetcode.cn/problems/split-a-string-into-the-max-number-of-unique-substrings/description/
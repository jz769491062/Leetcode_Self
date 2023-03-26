class Solution {
    vector<string> res;
    vector<string> path;
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return res;
    }

    bool isValid(string& s, int start, int end) {
        int len = end - start + 1;
        if (len == 0 || len > 3) {
            return false;
        }
        if (len == 1) {
            return true;
        }
        // len 2 case
        if (s[start] == '0') {
            return false;
        } else if (len == 2) {
            return true;
        }
        // len 3 case
        if (stoi(s.substr(start, len)) > 255) {
            return false;
        }
        return true;
    }

    void backtrack(string& s, int start) {
        int n = s.size();
        if (start == n && path.size() == 4) {
            string tempPath = "";
            for (int i = 0; i < path.size(); i++) {
                tempPath += path[i];
                if (i < path.size() - 1) {
                    tempPath += ".";
                }
            }
            res.push_back(tempPath);
        }
        for (int i = start; i < n; i++) {
            if (path.size() == 4) break;
            if (!isValid(s, start, i)) {
                continue;
            }
            path.push_back(s.substr(start, i - start + 1));
            backtrack(s, i + 1);
            path.pop_back();
        }
    }
};// https://leetcode.cn/problems/restore-ip-addresses/description/?company_slug=huawei
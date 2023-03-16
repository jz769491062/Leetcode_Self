class Solution {
    vector<vector<int>> memo;
    // 这个char都在哪些索引出现?
    unordered_map<char, vector<int>> charToIdxMap;
public:
    int findRotateSteps(string ring, string key) {
        // 当圆盘指针指向 ring[i] 时，输入字符串 key[j..] 至少需要 dp(ring, i, key, j) 次操作
        int m = ring.size(), n = key.size();
        memo.resize(m, vector<int>(n));
        for (int i = 0; i < ring.size(); i++) {
            char c = ring[i];
            charToIdxMap[c].push_back(i);
        }
        return DP(ring, key, 0, 0);
    }

    int DP(string& ring, string& key, int i, int j) {
        // base case
        if (j == key.size()) return 0;
        // memo的0就算特殊值了
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        int n = ring.size();
        int res = INT_MAX;
        for (int k : charToIdxMap[key[j]]) {
            int switchCount = abs(k - i);
            // 顺时针还是逆时针
            switchCount = min(switchCount, n - switchCount);
            // 开始匹配下一个
            int subProblem = DP(ring, key, k, j + 1);
            // 按按钮也算一步，所以+1
            // 之前的结果好，还是这个新结果（并按下当前字符）好?
            res = min(res, switchCount + subProblem + 1);
        }
        memo[i][j] = res;
        return res;
    }
};// https://leetcode.cn/problems/freedom-trail/description/
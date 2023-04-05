class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        int res = 0;
        for (vector<int>& v : wall) {
            if (v.size() == 1) continue;
            vector<int> currSum(v.size());
            currSum[0] = v[0];
            m[currSum[0]]++;
            res = max(res, m[currSum[0]]);
            for (int i = 1; i < v.size() - 1; i++) {
                int newSum = currSum[i - 1] + v[i];
                currSum[i] = newSum;
                m[newSum]++;
                res = max(res, m[newSum]);
            }
        }
        return wall.size() - res;
    }
};// https://leetcode.cn/problems/brick-wall/description/?company_slug=huawei
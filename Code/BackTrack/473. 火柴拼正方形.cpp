class Solution {
    int edge;
    vector<bool> visited;
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int i : matchsticks) {
            sum += i;
        }
        if (sum % 4 != 0) {
            return false;
        }
        visited.resize(matchsticks.size());
        edge = sum / 4;
        if (edge < matchsticks[0]) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
        return dfs(matchsticks, edge, 0, 0);
    }

    bool dfs(vector<int>& matchsticks, int remain, int start, int edgeIdx) {
        int n = matchsticks.size();
        if (edgeIdx == 3) {
            return true;
        }
        if (remain == 0) {
            return dfs(matchsticks, edge, 0, edgeIdx + 1);
        }
        for (int i = start; i < n; i++) {
            if (matchsticks[i] <= remain && !visited[i]) {
                visited[i] = true;
                if (dfs(matchsticks, remain - matchsticks[i], i + 1, edgeIdx)) {
                    return true;
                }
                visited[i] = false;
                // 剪枝: 相同长度火柴棍只选一个 ?
                while (i >= 1 && matchsticks[i] == matchsticks[i - 1]) {
                    i++;
                }
            }
        }
        return false;
    }
};
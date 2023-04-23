class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        queue<int> q;
        vector<bool> visited(amount + 1);
        q.push(amount);
        visited[amount] = true;
        int res = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                for (int coin : coins) {
                    int next = curr - coin;
                    if (next < 0) {
                        continue;
                    }
                    if (next == 0) {
                        return res;
                    }
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};// https://leetcode.cn/problems/coin-change/description/
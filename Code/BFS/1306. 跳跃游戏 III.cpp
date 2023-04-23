class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n);
        q.push(start);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (arr[curr] == 0) {
                return true;
            }
            int nextfront = curr + arr[curr];
            int nextback = curr - arr[curr];
            if (nextfront < n && !visited[nextfront]) {
                q.push(nextfront);
                visited[nextfront] = true;
            }
            if (nextback >= 0 && !visited[nextback]) {
                q.push(nextback);
                visited[nextback] = true;
            }
        }
        return false;
    }
};// https://leetcode.cn/problems/jump-game-iii/description/
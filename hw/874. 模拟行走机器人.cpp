class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 北、东、南、西
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        unordered_set<pair<int, int>, pair_hash> obstacleSet;
        for (vector<int>& obstacle: obstacles) {
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));
        }

        int ans = 0;
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }

        return ans;
    }

private:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1,T2>& myPair) const {
            size_t first = std::hash<T1>()(myPair.first);
            size_t second = std::hash<T2>()(myPair.second);
            return first ^ second;
        }
    };
};// https://leetcode.cn/problems/walking-robot-simulation/description/
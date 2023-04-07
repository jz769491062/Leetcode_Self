class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIndex = 0;
        int x = 0, y = 0;
        for (int i = 0; i < instructions.size(); i++) {
            if (instructions[i] == 'L') {
                dirIndex = (dirIndex + 3) % 4;
            } else if (instructions[i] == 'R') {
                dirIndex = (dirIndex + 1) % 4;
            } else {
                x += dir[dirIndex][0];
                y += dir[dirIndex][1];

            }
        }
        // 如果回到原点说明有环；如果没回到原点但循环结束后方向改变了，那么多执行2或4次还是能回到原点
        return (x == 0 && y == 0) || dirIndex != 0;
    }
};// https://leetcode.cn/problems/robot-bounded-in-circle/
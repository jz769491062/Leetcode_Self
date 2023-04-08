class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int maxRemain = max(memory1, memory2);
        bool oneMax = false;
        if (memory1 >= memory2) {
            oneMax = true;
        }
        vector<int> res(3);
        int time = 1;
        while (time <= maxRemain) {
            if (oneMax) {
                memory1 -= time;
            } else {
                memory2 -= time;
            }
            oneMax = memory1 >= memory2 ? true : false;
            maxRemain = max(memory1, memory2);
            time++;
        }
        res[0] = time;
        res[1] = memory1;
        res[2] = memory2;
        return res;
    }
};// https://leetcode.cn/problems/incremental-memory-leak/description/
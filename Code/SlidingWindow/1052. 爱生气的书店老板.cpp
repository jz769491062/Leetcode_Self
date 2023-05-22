// https://leetcode.cn/problems/grumpy-bookstore-owner/description/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total = 0;
        int n = customers.size();
        // 先算总能满意的sum
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                total += customers[i];
            }
        }
        // 初始窗口大小是minutes
        int increase = 0;
        for (int i = 0; i < minutes; i++) {
            increase += customers[i] * grumpy[i];
        }
        int maxInc = increase;
        for (int i = minutes; i < n; i++) {
            increase = increase 
            - customers[i - minutes] * grumpy[i - minutes] 
            + customers[i] * grumpy[i];
            maxInc = max(maxInc, increase);
        }
        return total + maxInc;
    }
};
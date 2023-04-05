class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 贪心：从当前总盈亏线的最低点加油站出发
        int n = gas.size();
        int sum = 0, minSum = 0;
        int start = 0; // 从哪个加油站开始
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            if (sum < minSum) {
                // 注意需要更新MinSum时才更新start
                start = i + 1;
                minSum = sum;
            }
        }
        if (sum < 0) {
            return -1;// 怎么样都无解
        }
        // 注意环形数组特点
        return start == n ? 0 : start;
    }
};// https://leetcode.cn/problems/gas-station/description/?company_slug=huawei
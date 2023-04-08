class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int res = -1;
        if (4 * boardingCost <= runningCost) {
            return res;
        }
        // 模拟4轮摩天轮是没有意义的，因为到站下车，每次上车时摩天轮座位总是空的！只管往里面装就是了
        int maxProfit = 0;
        int total = 0;
        int operations = 0;
        int customerCount = 0;
        for (int i = 0; i < customers.size(); i++) {
            operations++;
            customerCount += customers[i];
            int currCustomerCount = min(customerCount, 4);
            customerCount -= currCustomerCount;
            total += boardingCost * currCustomerCount - runningCost;
            if (total > maxProfit) {
                maxProfit = total;
                res = operations;
            }
        }
        if (customerCount == 0) {
            // 正好服务完，肯定最大化了
            return res;
        } else {
            // 装剩余的游客
            int fulls = customerCount / 4;
            total += fulls * (4 * boardingCost - runningCost);
            operations += fulls;
            if (total > maxProfit) {
                maxProfit = total;
            }
            int remain = customerCount % 4;
            total += remain * boardingCost - runningCost;
            if (total > maxProfit) {
                maxProfit = total;
                operations++;
            }
            res = operations;
        }
        return res;
    }
};// https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/description/
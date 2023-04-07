// https://leetcode.cn/problems/number-of-orders-in-the-backlog/
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // 如同买股票，想低买高卖
        priority_queue<pair<int,int>> buy;//大顶堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> sell;//小顶堆
        int res = 0, mod = pow(10, 9) + 7;
        for (vector<int>& v : orders) {
            if (v[2] == 0) {
                while (v[1] > 0 && !sell.empty() && sell.top().first <= v[0]) {
                    auto [price, amount] = sell.top();
                    sell.pop();
                    if (amount <= v[1]) {
                        // 卖得少，减去买的订单的数量即可
                        // 注意取模一定要这样计算，括号内的！
                        res = (res - amount + mod) % mod; // 还剩多少订单
                        v[1] -= amount;
                    } else {
                        // 买的数量更少，那卖的积压订单增多
                        sell.push({price, amount - v[1]});
                        res = (res - v[1] + mod) %mod;
                        v[1] = 0;
                    }
                }
                // 剩余的订单作为积压加入堆和res
                if (v[1] > 0) {
                    buy.push({v[0], v[1]});
                    // res += v[1];
                    res = (res + v[1]) % mod; // 注意取模！
                }
            } else {
                while (v[1] > 0 && !buy.empty() && buy.top().first >= v[0]) {
                    auto [price, amount] = buy.top();
                    buy.pop();
                    if (amount <= v[1]) {
                        // 买得少，减去卖的订单的数量即可
                        // 注意取模一定要这样计算，括号内的！
                        res = (res - amount + mod) % mod; // 还剩多少订单
                        v[1] -= amount;
                    } else {
                        // 卖的数量更少，那买的积压订单增多
                        buy.push({price, amount - v[1]});
                        res = (res - v[1] + mod) %mod;
                        v[1] = 0;
                    }
                }
                // 剩余的订单作为积压加入堆和res
                if (v[1] > 0) {
                    sell.push({v[0], v[1]});
                    // res += v[1];
                    res = (res + v[1]) % mod; // 注意取模！
                }
            }
        }
        return res;
    }
};
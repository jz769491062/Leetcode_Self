class StockSpanner {
    stack<pair<int, int>> stk; //price, span
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int res = 1;
        while (!stk.empty() && stk.top().first <= price) {
            res += stk.top().second;
            stk.pop();
        }
        // 直接把此前计算过的跨度存储在栈里，供后续元素查看
        stk.push({price, res});
        return res;
    }
};// https://leetcode.cn/problems/online-stock-span/description/

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class Solution {
public:
    int GetDays(vector<int>& weights, int limit) {
        int days = 0;
        for (int i = 0; i < weights.size();) { // 注意i++工作全在循环内完成了，这里不要自增了
            // 每个循环尝试装满，每个循环是1day
            int l = limit;
            while (i < weights.size()) {
                if (l < weights[i]) {// 装不下这件就break留到下一天去
                    break;
                }
                l -= weights[i];
                i++;
            }
            days++;
        }
        // cout << "days: " << days << endl;
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // 最小化x载重，让fx 满足days的限制。x和fx反比
        // 还是寻找载重的最左边
        // 载重的最小值和最大值是多少？
        // 最小值，是所有货物中最重的，至少能把一件最重的带走
        // 最大值，注意，应该是所有货物重量的总和！
        int left = 0, right = 0;
        for (int& w : weights) {
            left = max(left, w);
            right += w;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            int day = GetDays(weights, mid);
            if (day <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};//https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/description/
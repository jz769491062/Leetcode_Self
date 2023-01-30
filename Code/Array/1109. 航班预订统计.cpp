// https://leetcode.cn/problems/corporate-flight-bookings/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 差分数组
        vector<int> diff(n);
        //遍历修改diff数组
        for (int i = 0; i < bookings.size(); i++) {
            int startIdx = bookings[i][0] - 1; // 注意本题index从1开始
            int endIdx = bookings[i][1] - 1; // 注意本题index从1开始
            int inc = bookings[i][2];
            diff[startIdx] += inc;
            // 注意，如果最后一位数也要inc，那末尾diff元素就没必要-inc了，因为和倒数第二位比都inc了同样的数值
            // 所以只在endIdx不是最后一个数的时候我们才需要-=inc
            if (endIdx < n - 1) {
                diff[endIdx + 1] -= inc;
            }
        }
        // 推算修改后的数组
        vector<int> res(n);
        res[0] = diff[0];
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
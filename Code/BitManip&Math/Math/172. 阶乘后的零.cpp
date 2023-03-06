class Solution {
public:
    int trailingZeroes(int n) {
        // 结尾有0，那一定是 2 * 5的结果
        // 问题转化为：n! 最多可以分解出多少个因子 2 和 5
        // 因子2的数量肯定比5多得多，所以看有多少个因子5即可
        // 比如125!: 首先 125/5 = 25, 然后125/25 = 5个25的倍数，然后125/125 = 1个125的倍数，都可提供因子5
        // 所以125!里有25+5+1 = 31个末尾0
        // O(log N)
        int res = 0;
        long divisor = 5;
        while (divisor <= n) {
            res += n / divisor;
            divisor *= 5;
        }
        return res;
    }
};// https://leetcode.cn/problems/factorial-trailing-zeroes/description/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        // 一个数如果是 2 的指数，那么它的二进制表示一定只含有一个 1
        return (n & (n - 1)) == 0;
    }
};// https://leetcode.cn/problems/power-of-two/description/
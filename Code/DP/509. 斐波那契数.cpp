class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        //a, b 相当于大小为2的DP table， dp[i-1] 和 dp[i-2]
        int a = 0;
        int b = 1;
        for (int i = 2; i <= n; i++) {
            int curr = a + b;
            a = b;
            b = curr;
        }
        return b;
    }
};//https://leetcode.cn/problems/fibonacci-number/description/
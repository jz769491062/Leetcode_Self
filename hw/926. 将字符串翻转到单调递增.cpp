class Solution {
public:
    int minFlipsMonoIncr(string &s) {
        int dp0 = 0, dp1 = 0;
        for (char c: s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') {
                dp0New++;
            } else {
                dp1New++;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/flip-string-to-monotone-increasing/solutions/1592230/jiang-zi-fu-chuan-fan-zhuan-dao-dan-diao-stjd/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 异或的性质：a ^ a == 0    a ^ 0 == a
        int res = 0;
        for (int n : nums) {
            res ^= n;
        }
        return res;
    }
};// https://leetcode.cn/problems/single-number/description/
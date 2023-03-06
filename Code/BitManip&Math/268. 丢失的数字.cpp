class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 只要把所有的元素和索引做异或运算，成对儿的数字都会消为 0，只有这个落单的元素会剩下
        // 题目的nums如果我们补一位，就相当于其中一个数字装了个0，剩下的数字和索引完全对应
        int n = nums.size();
        int res = 0;
        // 先和我们补的索引，也就是Nums[n]，异或一下
        res ^= n;
        for (int i = 0; i < n; i++) {
            res ^= (i ^ nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 这个题目相当于：现在有个等差数列 0, 1, 2,..., n，其中少了某一个数字，请你把它找出来。那这个数字就是 sum(0,1,..n) - sum(nums)
        int n = nums.size();
        // 注意一个0~9的等差数列有10个数字
        long total = (0 + n) * (n + 1) / 2;
        long sum = 0;
        for (int x : nums) {
            sum += x;
        }
        return (int) (total - sum);
    }
};// https://leetcode.cn/problems/missing-number/description/
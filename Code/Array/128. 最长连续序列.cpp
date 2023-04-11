class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int num : nums) {
            mySet.insert(num);
        }
        int res = 0;
        for (int num : mySet) {
            // num 不是连续子序列的第一个，跳过
            if (mySet.count(num - 1)) continue;
            // num 是连续子序列的第一个，开始向上计算连续子序列的长度
            // 这个问题的子问题：如果已知这个连续序列数字开头是几，求序列总长度。
            // 然后：找到开头，也就是前无来者，num - 1不在nums里
            int currNum = num;
            int currLen = 1;
            while (mySet.count(currNum + 1)) {
                currNum ++;
                currLen++;
            }
            res = max(res, currLen);
        }
        return res;
    }
};// https://leetcode.cn/problems/longest-consecutive-sequence/description/
// https://leetcode.cn/problems/range-addition/
/*
差分数组：
数组8  5  9  6  1
差分8 -3  4  -3  -5
如果对5, 9, 6加3：
数组8  8  12  9  1
差分8  0  4  -3  -8
     (+3)        (-3)
所以，要对[left, right] + 3，就对diff[left] + 3，然后diff[right + 1] - 3，即可推算
*/
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // 前缀和是用来快速求某一个区间的和的，而差分数组是用来快速求 对数组一堆区间进行一系列加减后 数组变成了什么样。
        vector<int> diff(length);
        //遍历修改diff数组
        for (int i = 0; i < updates.size(); i++) {
            int startIdx = updates[i][0];
            int endIdx = updates[i][1];
            int inc = updates[i][2];
            diff[startIdx] += inc;
            // 注意，如果最后一位数也要inc，那末尾diff元素就没必要-inc了，因为和倒数第二位比都inc了同样的数值
            // 所以只在endIdx不是最后一个数的时候我们才需要-=inc
            if (endIdx < length - 1) {
                diff[endIdx + 1] -= inc;
            }
        }
        // 推算修改后的数组
        vector<int> res(length);
        res[0] = diff[0];
        for (int i = 1; i < length; i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int length = 1001; // 题目限制
        vector<int> diff(length);
        //遍历修改diff数组
        int minStart = 10000;
        int minStartNum = 0;
        for (int i = 0; i < trips.size(); i++) {
            int startIdx = trips[i][1];
            int endIdx = trips[i][2] - 1;//到站下车，所以下车那站就不算下车乘客了
            int inc = trips[i][0];
            if (inc > capacity) return false;
            if (startIdx < minStart) { // 确保差分数组第一位能正确算出第一个数字
                minStart = startIdx;
                minStartNum = inc;
            } else if (startIdx == minStart) { // 确保差分数组第一位能正确算出第一个数字
                minStartNum += inc;
            }
            diff[startIdx] += inc;
            // 注意，如果最后一位数也要inc，那末尾diff元素就没必要-inc了，因为和倒数第二位比都inc了同样的数值
            // 所以只在endIdx不是最后一个数的时候我们才需要-=inc
            // 哪怕只加一个数字，也还是endIdx+1要修改的，不要画蛇添足，不要假设，就自己推算
            if (endIdx < length - 1) {
                diff[endIdx + 1] -= inc;
            }
        }
        // 算修改后的数组，累加过程中是否有某一个时刻超过capacity，是则false
        int currSum = 0;
        diff[minStart] = minStartNum;
        // cout << minStart << " " << minStartNum << " diff:";
        // for (int i = 0; i < 10; i++) {
        //     cout << diff[i] <<" ";
        // }
        // cout << endl;
        for (int i = 0; i < length; i++) {
            currSum += diff[i];
            if (currSum > capacity) {
                return false;
            }
        }
        return true;
    }
};// https://leetcode.cn/problems/car-pooling/description/
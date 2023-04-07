class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max = arr[0];
        int winCount = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > max) {
                // 重置胜利次数然后更新maxx
                winCount = 1;
                max = arr[i];
            } else {
                winCount++;
            }
            if (winCount == k) return max;
        }
        // 都比完了，还没有达到k连胜的，那只能是最大值胜出了
        return max;
    }
};// https://leetcode.cn/problems/find-the-winner-of-an-array-game/
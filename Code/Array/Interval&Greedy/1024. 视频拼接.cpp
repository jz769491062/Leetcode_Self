class Solution {
public:
struct MyComp {
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return b[1] < a[1];
        }
        return a[0] < b[0];
    }
};
    int videoStitching(vector<vector<int>>& clips, int time) {
        // 求最小片段数目，也就是同起点的片段应该选最长的那个
        // 所以按起点升序排序，然后终点降序排序
        // 然后找终点更大的作为下一段拼接的目标
        if (time == 0) return 0;
        sort(clips.begin(), clips.end(), MyComp());
        int res = 0;
        int curEnd = 0, nextEnd = 0;
        int i = 0, n = clips.size();
        while (i < n && clips[i][0] <= curEnd) {
            // 在第 res 个视频的区间内贪心选择下一个视频
            while (i < n && clips[i][0] <= curEnd) {
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            }
            res++;
            curEnd = nextEnd;
            // 已经可以拼出来的话则return
            if (curEnd >= time) {
                return res;
            }
        }
        return -1;
    }
};// https://leetcode.cn/problems/video-stitching/description/
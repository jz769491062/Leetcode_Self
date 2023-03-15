class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), []
        (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // earliest finish time first
        });
        int toRemove = 0;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < right) {
                toRemove++;
            } else {
                right = intervals[i][1];
            }
        }
        return toRemove;
    }
};// https://leetcode.cn/problems/non-overlapping-intervals/description/
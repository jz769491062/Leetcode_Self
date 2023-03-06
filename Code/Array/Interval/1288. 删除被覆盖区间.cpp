class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 区间问题：1 排序 2 画图分析几种可能
        // 全覆盖、部分覆盖、完全不重叠
        // 按照起点升序排序、终点降序排序，这样长的区间在上面，顺序遍历的时候不会误判为相交
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0]) {
                    // 降序排序终点
                    return a[1] > b[1];
                }
                // 升序排序起点
                return a[0] < b[0];
        });
        // 记录一下合并区间的范围
        int left = intervals[0][0];
        int right = intervals[0][1];
        int toDeleteCount = 0;
        for (int i = 1; i < intervals.size(); i++) {
            int a = intervals[i][0], b = intervals[i][1];
            if (a >= left && b <= right) {
                // 完全重叠
                toDeleteCount++;
            }
            // 部分相交
            if (right >= a && right <= b) {
                right = b;
            }
            // 完全不相交
            if (a > right) {
                left = a;
                right = b;
            }
        }
        return intervals.size() - toDeleteCount;
    }
};// https://leetcode.cn/problems/remove-covered-intervals/description/
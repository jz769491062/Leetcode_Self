class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 对于一个合并后的区间，头部一定是所有相交区间中最小的，尾部一定是所有相交区间中最大的
        sort(intervals.begin(), intervals.end(), []
        (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; // 升序排列头部
        });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // 注意用引用更新res
            vector<int>& last = res[res.size() - 1];
            int a = intervals[i][0], b = intervals[i][1];
            // 如果已经完全重叠，不管
            if (a > last[1]) {
                // 如果不相交，push然后新开始一轮
                res.push_back(intervals[i]);
            } else if (a <= last[1]) {
                // 如果尾部更长，更新尾部
                last[1] = max(b, last[1]); // 注意max比较尾部哪个长
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/merge-intervals/description/
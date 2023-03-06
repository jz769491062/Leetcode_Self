class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), []
        (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // earliest finish time first
        });
        int res = 1;
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > right) {
                res++;
                right = points[i][1];
            }
            // 注意没有else的情况，我们只关心出现不重叠的新区域时的情况
        }
        return res;
    }
};// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/
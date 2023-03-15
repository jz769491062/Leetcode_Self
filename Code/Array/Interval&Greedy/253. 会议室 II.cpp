class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 模拟一条线扫描，经过起点+1，经过终点-1，维护过程中的最大值是多少
        vector<int> start, finish;
        int n = intervals.size();
        for (vector<int>& v : intervals) {
            start.push_back(v[0]);
            finish.push_back(v[1]);
        }
        // 注意：线段扫描，那自然需要降序排序起点和终点
        sort(start.begin(), start.end());
        sort(finish.begin(), finish.end());
        int i = 0, j = 0, tempcnt = 0;
        int res = 0;
        while (i < n && j < n) {
            if (start[i] < finish[j]) {
                tempcnt++;
                i++;
            } else {
                tempcnt--;
                j++;
            }
            res = max(res, tempcnt);
        }
        return res;
    }
};// https://leetcode.cn/problems/meeting-rooms-ii/description/
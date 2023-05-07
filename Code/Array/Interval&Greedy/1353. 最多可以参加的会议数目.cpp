// https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/description/?company_slug=huawei
class Solution {
    int MAX_DAYS = 1e5 + 1;
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<vector<int>> dayToIdx(MAX_DAYS);
        // 快速获取当前时间开始的会议，把开始时间映射到区间idx
        for (int i = 0; i < events.size(); i++) {
            dayToIdx[events[i][0]].push_back(i);
        }
        int res = 0;
        // 最早结束时间的会议
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 1; i < MAX_DAYS; i++) {
            // 通过开始日期找对应区间，然后push结束时间进队列
            for (int j : dayToIdx[i]) {
                pq.push(events[j][1]);
            }
            // 已经结束的会议移除
            while (!pq.empty() && pq.top() < i) {
                pq.pop(); 
            }
            // 剩下一个结束时间最早的会议去参加, +1
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }
        return res;
    }
};
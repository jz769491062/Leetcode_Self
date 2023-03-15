class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // 题目已经排好序了
        // 交集的核心：如果交集区间是[c1,c2]，那么c1=max(a1,b1)，c2=min(a2,b2)
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < firstList.size() && j < secondList.size()) {
            int a1 = firstList[i][0], a2 = firstList[i][1];
            int b1 = secondList[j][0], b2 = secondList[j][1];
            if (b1 <= a2 && a1 <= b2) {
                // 有交集
                res.push_back({max(a1, b1), min(a2, b2)});
            }
            // 哪个尾部更靠前，就推进哪个指针
            if (a2 <= b2) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/interval-list-intersections/description/
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // 1 面积 2 顶点
        // 一个完美矩形，肯定面积是一个矩形，而且有4个符合理论的顶点
        // 当某一个点同时是 2 个或者 4 个小矩形的顶点时，该点最终不是顶点；当某一个点同时是 1 个或者 3 个小矩形的顶点时，该点最终是一个顶点。
        set<pair<int, int>> points;
        long actualArea = 0;
        int x = INT_MAX, y = INT_MAX, a = INT_MIN, b = INT_MIN;
        vector<pair<int,int>> temp; // 遍历用
        for (vector<int>& v : rectangles) {
            // 不断找左下右上顶点
            x = min(v[0], x);
            y = min(v[1], y);
            a = max(v[2], a);
            b = max(v[3], b);
            // 把每个矩形面积加起来
            long tempProduct = (long)((long)(v[2] - v[0]) * (long)(v[3] - v[1]));
            actualArea += tempProduct;
            pair<int, int> p1 = {v[0], v[1]}, p2 = {v[0], v[3]}, p3 = {v[2], v[1]}, p4 = {v[2], v[3]};
            temp.clear();
            temp.push_back(p1);temp.push_back(p2);temp.push_back(p3);temp.push_back(p4);
            for (pair<int,int> p : temp) {
                // 奇数的留在set里，偶数的剔除set，这样留下的全是顶点
                if (points.count(p)) {
                    points.erase(p);
                } else {
                    points.insert(p);
                }
            }
        }
        long expectedArea = (long)((long)(a - x) * (long)(b - y));
        if (actualArea != expectedArea) {
            return false; // 面积不符合理论，false
        }
        if (points.size() != 4) {
            return false; // 顶点不是4个，false
        }
        // 注意，然后还要判定4个顶点是否是完美矩形的理论顶点，因为有可能小矩形完全重叠
        // 比如 https://labuladong.gitee.io/algo/images/%e5%ae%8c%e7%be%8e%e7%9f%a9%e5%bd%a2/3.jpeg
        if (!points.count({x, y})) return false;
        if (!points.count({x, b})) return false;
        if (!points.count({a, y})) return false;
        if (!points.count({a, b})) return false;
        return true;
    }
};// https://leetcode.cn/problems/perfect-rectangle/description/
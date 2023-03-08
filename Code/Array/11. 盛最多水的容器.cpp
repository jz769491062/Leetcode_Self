class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();// 防止unsigned overflow
        int left = 0;
        int right = n - 1;
        int res = 0;
        while (left < right) {
            // 短板决定盛水高度
            res = max(res, min(height[left], height[right]) * (right - left));
            // 哪边短更新哪边，尝试找一个更长的板
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/container-with-most-water/description/
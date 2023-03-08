class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // 定义：当前格子左手边最高的高度是？
        vector<int> lmax(n);
        lmax[0] = height[0];
        // 定义：当前格子右手边最高的高度是？
        vector<int> rmax(n);
        rmax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            lmax[i] = max(height[i], lmax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(height[i], rmax[i + 1]);
        }
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            // 注意短板决定高度，所以用Min，然后再减去这一格子的高度
            res += min(lmax[i], rmax[i]) - height[i];
        }
        return res;
    }
};
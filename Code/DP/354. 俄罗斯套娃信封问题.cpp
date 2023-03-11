class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            // return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
    
        vector<int> height(n);
        for (int i = 0; i < n; i++) {
            height[i] = envelopes[i][1];
        }
        return LongestIncreasingSequence(height);
    }
    
    int LongestIncreasingSequence(vector<int>& nums) {
        int piles = 0;
        int n = nums.size();
        vector<int> top(n);
        for (int i = 0; i < n; i++) {
            int card = nums[i];
            int left = 0;
            int right = piles;
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] >= card) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            // 利用左侧边界没找到的情况，找最长子序列
            if (left == piles) piles++;
            top[left] = card;
        }
        // 牌堆数是最长子序列长度
        return piles;
    }// https://labuladong.gitee.io/algo/di-er-zhan-a01c6/dong-tai-g-a223e/dong-tai-g-6ea57/
};// https://leetcode.cn/problems/russian-doll-envelopes/
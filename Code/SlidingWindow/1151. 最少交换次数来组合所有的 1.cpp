class Solution {
public:
    int minSwaps(vector<int>& data) {
        int cnt = 0; // 总共多少个1
        for (int i : data) {
            if (i == 1) {
                cnt++;
            }
        }
        unordered_map<char, int> window;
        for (int i = 0; i < cnt; i++) {
            window[data[i]]++;
        }
        int res = window[0];
        for (int i = cnt; i < data.size(); i++) {
            window[data[i]]++;
            window[data[i - cnt]]--;
            res = min(res, window[0]);
        }
        return res;
    }
};// https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together/description/
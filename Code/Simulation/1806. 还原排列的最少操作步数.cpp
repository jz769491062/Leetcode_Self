class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n), target(n);
        iota(perm.begin(), perm.end(), 0);
        iota(target.begin(), target.end(), 0);
        int step = 0;
        while (true) {
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    arr[i] = perm[i / 2];
                } else {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            perm = move(arr);
            step++;
            if (perm == target) {
                break;
            }
        }
        return step;
    }
};// https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/description/
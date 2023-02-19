/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // 对于两个人来说，有4种关系：互相认识，互相不认识，单方面认识。
        // 单方面认识的，那个认识的人肯定不是名人，排除
        // 互相认识/不认识的，肯定都不是名人，排除
        int cand = 0;// 假定cand是名人
        for (int other = 1; other < n; other++) {
            // cand不可能是名人的case
            if (knows(cand , other) || !knows(other , cand)) {
                cand = other;
            }
        }
        // 上述是两两比对的筛查结果，接下来对于可能的cand，再和所有人检查一遍是否是名人才够
        for (int other = 0; other < n; other++) {
            if (cand == other) continue; // 注意，跳过自己
            if (knows(cand , other) || !knows(other , cand)) {
                return -1;
            }
        }
        return cand;
    }
};// https://leetcode.cn/problems/find-the-celebrity/description/ O(n)速度 O(1)空间
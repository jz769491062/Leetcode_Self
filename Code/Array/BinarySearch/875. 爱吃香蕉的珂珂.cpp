// https://leetcode.cn/problems/koko-eating-bananas/
// https://mp.weixin.qq.com/s/JgJ0jh2SJd6grQSPnN6Jww
class Solution {
public:
    int timeNeeded(vector<int>& piles, int eatingSpeed) {
        int time = 0;
        for (int p : piles) {
            time += p/eatingSpeed;
            if (p % eatingSpeed > 0) {
                ++time;
            }
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // 二分搜索关注这三个数字：自变量x, 因变量f(x)，target
        // 这道题x = 吃的速度，f(x) = 多久吃完, target = 时间限制
        // 目标是最小化X，同时f(x) <= H
        // https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdGDpGy94LrU7ugAkwOqdV0dAUkgxNHckTW0aicNa7zBIPCmFFe0sicGBscCvbw044gzficoPbNkfpATQ/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1
        // 也就是搜索x的左侧边界
        // 那么eatingspeed的范围是？
        // 最小是1，最大是piles[i]范围10 ^ 9 + 1(左闭右开+1)，题目要求，吃再快，1小时也只能吃1堆
        int left = 1, right = 1000000001;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int needTime = timeNeeded(piles, mid);
            if (needTime <= h) {
                right = mid;
            } else if (needTime > h) {
                left = mid + 1;
            }
        }
        return left;
    }
};
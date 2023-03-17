class Solution {
public:
// 反过来想这个问题：如果我们可以做 t 次操作，而且有 k 个鸡蛋，那么我们能找到答案的最高的 n 是多少？
// 我们设 f(t,k) 为在上述条件下的 n。如果我们求出了所有的 f(t,k)，那么只需要找出最小的满足 f(t,k)≥nf(t, k) 的 t
    int superEggDrop(int k, int n) {
        // k eggs, n floors, how many tries
        // we know tries always <= n
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        // base case:
        // dp[0][..] = 0
        // dp[..][0] = 0
        int res = 0;
        // 因为我们需要找出最高的n，因此我们不必思考到底在哪里扔这个鸡蛋，我们只需要扔出一个鸡蛋，看看到底发生了什么
        // 如果鸡蛋没有碎，那么对应的是 f(t−1,k)，也就是说在这一层的上方可以有 f(t−1,k)层；
        // 如果鸡蛋碎了，那么对应的是 f(t−1,k−1)，也就是说在这一层的下方可以有 f(t−1，k−1)层
        while (dp[k][res] < n) {
            res++;
            for (int i = 1; i <= k; i++) {
                dp[i][res] = dp[i][res - 1] + dp[i - 1][res - 1] + 1;
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/super-egg-drop/description/
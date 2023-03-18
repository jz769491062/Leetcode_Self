class Solution {
public:
    int maxA(int n) {
        // 再进一步压缩到2个状态，也就是2种最优策略：一直按A; 或者按几个A后CA/CC/CV后继续接CV
        // 最优的操作序列一定是 C-A C-C 接着若干 C-V，所以我们用一个变量 j 作为若干 C-V 的起点
        // dp数组定义：这次最后一个操作是A，还是CV？能使当前A数量最大化?
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            // 按A
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j < i; j++) {
                // 全选 & 复制 dp[j-2]，连续粘贴 i - j 次
                // 屏幕上共 dp[j - 2] * (i - j + 1) 个 A
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
            }
        }
        return dp[n];
    }
};


// 超时解
class Solution {
public:
    int maxA(int n) {
        // 状态：还能按几次，已经打了几个A，剪贴板里多少个A
        // 那么按下A就是dp(n - 1, curr + 1, copy)
        // CA&CC(CA单独使用无意义)就是dp(n - 2, curr, copy = curr)
        // CV 就是 dp(n - 1, curr + copy, copy)

        map<tuple<int,int,int>, int> memo;

        // 定义 dp 函数
        function<int(int,int,int)> dp = [&](int n, int curr, int copy) -> int {
            // base case
            if(n <= 0) return curr;
            auto key = make_tuple(n, curr, copy);
            if(memo.count(key)) return memo[key];
            // 几种选择全试一遍，选择最大的结果
            memo[key] = max({dp(n-1, curr + 1, copy), dp(n-1, curr + copy, copy), dp(n-2, curr, curr)});
            return memo[key];
        };

        // 可以按 N 次按键，屏幕和剪切板里都还没有 A
        return dp(n, 0, 0);

    }
};// https://leetcode.cn/problems/4-keys-keyboard/
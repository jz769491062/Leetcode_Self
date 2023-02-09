//https://mp.weixin.qq.com/s/kcwz2lyRxxOsC3n11qdVSw
//https://leetcode.cn/problems/unique-binary-search-trees/
class Solution {
public:
vector<vector<int>> memo;
    int cnt(int lo, int hi) {
        if (lo > hi) return 1;
        if (memo[lo][hi] != 0) return memo[lo][hi];
        int res = 0;
        // 对于每一节可能的区间，算对应的BST组合有多少，累乘加起来就是整个子树多少个BST
        // 但是这样会有很多重复计算，所以需要备忘录
        for (int i = lo; i <= hi; i++) {
            int l = cnt(lo, i - 1);
            int r = cnt(i + 1, hi);
            res += l * r;
        }
        memo[lo][hi] = res;
        return res;
    }

    int numTrees(int n) {
        memo.resize(n + 1, vector<int>(n + 1));
        // 对于每个节点，左右子树的组合数相乘就是总共能有多少个BST
        return cnt(1, n);
    }
};
class Solution {
public:
    // 使用回溯法的思路思考，则每当选择一个数加入排列时，可以计算出剩下的数还有多少种排列的可能，
    // 即可以计算出当前被选择的数的排列总数，设用 remain_fac 表示， remain_fac = 剩下的待选择的数的阶乘。
    // 然后将 remain_fac 与 k 进行大小比较，若小于 k ，则说明所要求的第 k 个排列不在以 当前选定的数 为开头的所有排列中，直接跳过
    // 一次递归到底就能找到 第 k 个排列
    string getPermutation(int n, int k) {
        vector<bool> isUsed(n + 1, false);          // 每个数是否用过
        string res = "";
        dfs(isUsed, res, n, k);
        return res;
    }
    // 递归实现
    void dfs(vector<bool> &isUsed, string &res, int n, int k){
        int res_len = res.size();
        if(res_len == n){
            return;
        }
        int remain_fac = factorial(n - res_len - 1);  // 剩下的数的全排列的个数
        for(int i = 1; i <= n; ++i){
            if (isUsed[i]) {
                continue;
            }
            if(remain_fac > 0 && remain_fac < k){     // 剩下的数的全排列个数小于当前 k ，说明第 k 个排列肯定不在当前的递归子树中，直接跳过该递归
                k -= remain_fac;                      // 剪枝
                continue;
            }
            res = res + static_cast<char>('0' + i);
            isUsed[i] = true;
            dfs(isUsed, res, n, k);
            // 因为是一次递归直接到叶子，所以不需要还原状态
        }
    }

    int factorial(int n){
        int res = 1;
        while(n > 0){
            res *= n;
            n--;
        }
        return res;
    }
};// https://leetcode.cn/problems/permutation-sequence/description/
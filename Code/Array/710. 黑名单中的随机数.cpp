class Solution {
public:
int realSize; // 去除黑名单还有几个数字
// 黑名单数字-realSize后合法数字的映射
unordered_map<int, int> mapping; // 如果这是一个黑名单数字，就把这个数字映射到realSize之后的某个合法数字上，仿佛把blacklist集中在数组末尾，只对realSize部分做替换
    Solution(int n, vector<int>& blacklist) {
        realSize = n - blacklist.size();
        for (int b: blacklist) {
            // 先能在mapping里找到黑数字再说
            mapping[b] = 666;//还不知道该映射到哪个合法数字呢，别急
        }
        int last = n - 1;
        for (int b : blacklist) {
            // 已经在realSize后的黑名单数字不需要再映射了
            if (b >= realSize) {
                continue;
            }
            // 从后往前，在realSize后找一个可以映射的合法数字
            // 这道题数组就是0~n-1，数字本身就是索引
            while(mapping.count(last)) {
                last--;
            }
            mapping[b] = last;
            last--;
        }
    }
    
    int pick() {
        int idx = rand() % realSize;
        if (mapping.count(idx)) {
            return mapping[idx];
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */// https://leetcode.cn/problems/random-pick-with-blacklist/description/
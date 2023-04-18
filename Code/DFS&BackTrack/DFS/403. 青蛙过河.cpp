// https://leetcode.cn/problems/frog-jump/description/
class Solution {
    unordered_map<int, int> valToIdxMap;
    unordered_map<int, bool> cache;
    int n;
public:
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1) return false;
        for (int i = 0; i < n; i++) {
            valToIdxMap[stones[i]] = i;
        }
        // 默认从stones[1]起跳
        return dfs(stones, 1, 1);
    }

    bool dfs(vector<int>& stones, int idx, int step) {
        // cache要和下标以及跳跃步数都关联起来，所以我们可以自定义一个key实现这样的关联。
        int cacheKey = idx * 2001 + step;
        if (cache.count(cacheKey)) {
            return cache[cacheKey];
        }
        if (idx == n - 1) {
            return true;
        }
        for (int i = -1; i <= 1; i++) {
            if (step + i == 0) continue; // 在第一步stones[1]时往回跳一格属于无用功
            int next = stones[idx] + step + i;
            if (valToIdxMap.count(next)) {// 如果确实能跳到一块已有的石头上
                bool curr = dfs(stones, valToIdxMap[next], step + i);
                cache[cacheKey] = curr;
                if (curr) {
                    return true;
                }
            }
        }
        cache[cacheKey] = false;
        return false;
    }
};
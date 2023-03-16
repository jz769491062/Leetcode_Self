class Solution {
    // 哈希表记录每个点的入度
    // to -> [from, price]
    unordered_map<int, vector<vector<int>>> indegree;
    int src, dst;
    vector<vector<int>> memo;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 将中转站个数转化成边的条数
        k++;
        this->src = src;
        this->dst = dst;

        memo = vector<vector<int>>(n, vector<int>(k + 1, -666));

        for (auto f : flights) {
            int from = f[0];
            int to = f[1];
            int price = f[2];
            // 记录谁指向该节点，以及之间的权重
            indegree[to].push_back({from, price});
        }
        
        return DP(dst, k);
    }

    // 定义：从 src 出发，k 步之内到达 s 的最短路径权重
    int DP(int s, int k) {
        if (s == src) {
            // 先检查是否已经到达目的地
            return 0;
        }
        if (k == 0) {
            // 然后步数是否用尽
            return -1;
        }
        if (memo[s][k] != -666) {
            return memo[s][k];
        }
        // 初始化为最大值，方便等会取最小值
        int res = INT_MAX;
        if (indegree.count(s)) {
            // 当 s 有入度节点时，分解为子问题
            for (auto v : indegree[s]) {
                int from = v[0];
                int price = v[1];
                // 从 src 到达相邻的入度节点所需的最短路径权重
                int subProblem = DP(from, k - 1);
                // 跳过无解的情况
                if (subProblem != -1) {
                    res = min(res, subProblem + price);
                }
            }
        }
        // 如果还是初始值，说明此节点不可达
        memo[s][k] =  res == INT_MAX ? -1 : res;
        return memo[s][k];
    }
};// https://leetcode.cn/problems/cheapest-flights-within-k-stops/description/
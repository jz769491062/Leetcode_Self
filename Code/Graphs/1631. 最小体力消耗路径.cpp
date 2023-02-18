class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // 注意是所有高度差的最大值，才是消耗的体力。
        // 在矩阵遍历，需要确保加入了正确的neighbor，不要越界，所以加入adj函数
        return Dij(0, 0, heights);
    }

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // 返回邻居们的xy坐标
    vector<pair<int, int>> Adj(vector<vector<int>>& heights, int x, int y) {
        int m = heights.size(), n = heights[0].size();
        vector<pair<int, int>> res;
        for (pair<int, int>& d : dir) {
            // 方向数组+防范越界
            int nx = x + d.first, ny = y + d.second;
            if (nx >= m || nx < 0 || ny >= n ||ny < 0) continue;
            res.push_back({nx, ny});
        }
        return res;
    }

    class State {
    public:
        int x, y;
        int costFromStart;
        // 每个节点储存自己的id和起始到这的距离
        State(int x, int y, int costFromStart) {
            this->x = x;
            this->y = y;
            this->costFromStart = costFromStart;
        }
    };

    class Comp {
    public:
        bool operator()(State& A, State&B) {
            return A.costFromStart > B.costFromStart;//升序排序
        }
    };

    int Dij(int startX, int startY, vector<vector<int>>& heights) {
        // 初始化weight为max，然后Dij算法类似动态规划逐步缩小这些weight
        vector<vector<int>> costTo(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        // base case
        costTo[startX][startY] = 0;
        priority_queue<State, vector<State>, Comp> pq;
        State s(startX, startY, 0);
        pq.push(s);
        while(!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            int currX = curr.x;
            int currY = curr.y;
            int currCost = curr.costFromStart;
            if (currX == heights.size() - 1 && currY == heights[0].size() - 1) {
                return currCost;
            }
            // 如果比已有结果差，不必继续计算了
            if (currCost > costTo[currX][currY]) {
                continue;
            }
            // 装载相邻节点
            for (pair<int, int>& neighbor : Adj(heights, currX, currY)) {
                int nextX = neighbor.first, nextY = neighbor.second;
                // 计算costToNext, 注意用curr的,对比max
                int costToNext = max(costTo[currX][currY], abs(heights[nextX][nextY] - heights[currX][currY]));
                // 注意如果有所优化，才会更新，才会把节点加入队列
                // 因为加入队列条件不宽松，所以也不会出现回头路或者死循环
                // 因为dij要求节点weight不能为负数，回头路必定不是最优不会被选取
                if (costToNext < costTo[nextX][nextY]) {
                    costTo[nextX][nextY] = costToNext;
                    State better(nextX, nextY, costToNext);
                    pq.push(better);
                }
            }
        }
        return -1;//不会到达这里
    }
};
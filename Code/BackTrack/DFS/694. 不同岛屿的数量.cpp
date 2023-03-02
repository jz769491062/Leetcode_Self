class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, string& s, int dir) {
        int m = grid.size(), n = grid[0].size();
        // 注意海水直接return
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0) return;
        grid[x][y] = 0;
        s += to_string(dir) + ",";
        // 各个方向的遍历定义为1234以保证序列化
        dfs(grid, x + 1, y , s, 1);
        dfs(grid, x - 1, y , s, 2);
        dfs(grid, x, y + 1 , s, 3);
        dfs(grid, x, y - 1 , s, 4);
        // 撤销操作就是-1,-2,-3,-4
        // 记录撤销操作是必要的，比如说
        // 「下，右，撤销右，撤销下」和「下，撤销下，右，撤销右」显然是两个不同的遍历顺序
        s += to_string(-dir) + ",";
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        // 对于形状相同的岛屿，如果从同一起点出发，dfs 函数遍历的顺序肯定是一样的
        // 我们顺序遍历每个格子，所以相当于自带从同一起点触发，然后只关心遍历顺序即可
        /*
        如果我用分别用 1, 2, 3, 4 代表上下左右，用 -1, -2, -3, -4 代表上下左右的撤销，
        那么可以这样表示它们的遍历顺序：
        2, 4, 1, -1, -4, -2
        这就相当于是岛屿序列化的结果，只要每次使用 dfs 遍历岛屿的时候生成这串数字进行比较，就可以计算到底有多少个不同的岛屿了
        */
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> islandSet;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 注意不管海水
                if (grid[i][j] == 1) {
                    string s;
                    dfs(grid, i, j, s, 666); // 初始方向不重要
                    islandSet.insert(s);
                }
            }
        }
        return islandSet.size();
    }
};// https://leetcode.cn/problems/number-of-distinct-islands/
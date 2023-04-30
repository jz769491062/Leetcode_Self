class Solution {
/*
观察上图就能发现，如果二维数组中的某个元素 e 在一维数组中的索引为 i，那么 e 的左右相邻元素在一维数组中的索引就是 i - 1 和 i + 1，而 e 的上下相邻元素在一维数组中的索引就是 i - n 和 i + n，其中 n 为二维数组的列数。
这样，对于 m x n 的二维数组，我们可以写一个函数来生成它的 neighbor 索引映射
*/
    vector<vector<int>> neighbors = {
        {1, 3},
        {0, 4, 2},
        {1, 5},
        {0, 4},
        {3, 1, 5},
        {4, 2}
    };
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2, n = 3;
        string target = "123450";
        string start;
        // 起始状态
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start += to_string(board[i][j]);
            }
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            // 注意，一次扩散队列中所有元素
            for (int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();
                if (curr == target) {
                    return res;
                }
                int zeroIndex = 0;
                // 找到0的索引
                for (; curr[zeroIndex] != '0'; zeroIndex++);
                for (int neighbor : neighbors[zeroIndex]) {
                    // 交换，产生新state，加入queue
                    string newState = curr;
                    swap(newState[neighbor], newState[zeroIndex]);
                    if (!visited.count(newState)) {
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            res++; // 注意是在末尾更新移动步数，直到队列元素都被处理完才统计这一步数。
        }
        return -1;
    }
};// https://leetcode.cn/problems/sliding-puzzle/description/



class Solution {
// 状态压缩+ 双向BFS
public:
    static const int N = 50000;
    int pow_6[7];
    int dist_a[N], dist_b[N];
public:
    vector<int> get_moves(int state)
    {
        int idx_0 = 0, tmp_state = state;
        vector<int> res;
        while(tmp_state)
        {
            if(tmp_state % 6 == 0) break;
            tmp_state /= 6;
            idx_0 ++;
        }
        if(idx_0 != 2 && idx_0 != 5)
        {
            int num_minus_1 = (state / pow_6[idx_0 + 1]) % 6;
            // cout << "left: " << num_minus_1 << endl;
            res.push_back(state - num_minus_1 * pow_6[idx_0 + 1] + num_minus_1 * pow_6[idx_0]);
        }
        if(idx_0 != 3 && idx_0 != 0)
        {
            int num_plus_1 = (state / pow_6[idx_0 - 1]) % 6;
            // cout << "right: " << num_plus_1 << endl;
            res.push_back(state - num_plus_1 * pow_6[idx_0 - 1] + num_plus_1 * pow_6[idx_0]);
        }
        if(idx_0 + 3 < 6)
        {
            int num_minus_3 = (state / pow_6[idx_0 + 3]) % 6;
            // cout << "up: " << num_minus_3 << endl;
            res.push_back(state - num_minus_3 * pow_6[idx_0 + 3] + num_minus_3 * pow_6[idx_0]);
        }
        if(idx_0 - 3 >= 0)
        {
            int num_plus_3 = (state / pow_6[idx_0 - 3]) % 6;
            // cout << "down: " << num_plus_3 << endl;
            res.push_back(state - num_plus_3 * pow_6[idx_0 - 3]  + num_plus_3 * pow_6[idx_0]);
        }
        return res;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        memset(dist_a, -1, sizeof dist_a);
        memset(dist_b, -1, sizeof dist_b);
        int start = 0, end = 0, p = 1;
        for(int i = 0; i <= 6; i++)
            pow_6[i] = p, p *= 6;
        p = 1;
        for(int i = 1; i >= 0; i--)
            for(int j = 2; j >= 0; j--)
            {
                start +=  board[i][j] * p;
                p = p * 6;
            }
        p = 6;
        for(int i = 5; i >= 1; i--)
        {
            end += p * i;
            p = p * 6;
        }
        if(start == end) return 0;
        return bfs(start, end);
    }
    int extend(queue<int>& q, int da[], int db[])
    {
        int t = q.front();
        q.pop();
        vector<int> moves = get_moves(t);
        for(int m: moves)
        {
            if(db[m] != -1) return 1 + da[t] + db[m];
            if(da[m] != -1) continue;
            da[m] = da[t] + 1;
            q.push(m);
        }
        return -1;
    }
    int bfs(int start, int end)
    {
        queue<int> qa, qb;
        qa.push(start), dist_a[start] = 0;
        qb.push(end),   dist_b[end]   = 0;
        while(qa.size() && qb.size())
        {
            int t;
            if(qa.size() <= qb.size())
                t = extend(qa, dist_a, dist_b);
            else
                t = extend(qb, dist_b, dist_a);
            if(t != -1)
                return t;
        }
        return -1;
    }
};

// 作者：崔金浩_Official
// 链接：https://leetcode.cn/problems/sliding-puzzle/solutions/423771/c-zhuang-tai-ya-suo-bfs-by-cui-jin-hao-_official/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    string plusOne(string s, int i) {
        if (s[i] == '9') {
            s[i] = '0';
        } else {
            s[i]++;
        }
        return s;
    }
    string minusOne(string s, int i) {
        if (s[i] == '0') {
            s[i] = '9';
        } else {
            s[i]--;
        }
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> visited;//避免回头路，剪枝
        unordered_set<string> deadSet;//死胡同，搜索用
        q.push("0000");
        visited.insert("0000");
        int step = 0;
        for (auto v: deadends) {
            deadSet.insert(v);
        }
        while(!q.empty()) {
            int sz = q.size();
            // 扩散所有节点
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                // 注意，还是要有deadSet
                // 如果要优化成只有visited没有deadSet，那要考虑好如何处理入口"0000"以及visited的时机
                if (deadSet.count(cur)) continue;
                if (cur == target) {
                    return step;// BFS所以直接return即可
                }
                //注意，不要在这部分加入visited相关判断啊
                //梳理逻辑，cur此时就是已经visited了，正在处理了，那肯定是不能continue剪枝的。

                // 对于cur，每一位尝试+1, -1
                // 穷举1个step所能做的范围
                for (int j = 0; j < 4; j++) {
                    string up = plusOne(cur, j);
                    // 注意，很多visited重复就发生在穷举当前step范围的时候，所以要在这里就加入visited，而不是一开始
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    // visited在这里就已经控制好剪枝了，别的地方别加
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;//更新step
        }
        // 全搜索完毕，但没有达到target?那就return -1
        return -1;
    }
};// https://leetcode.cn/problems/open-the-lock/description/
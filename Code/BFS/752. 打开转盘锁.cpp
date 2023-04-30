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


// 双向BFS:
class Solution {
public:
    string s,t; 
    unordered_set<string> st;
    int openLock(vector<string>& deadends, string target) {
        s = "0000";
        t = target;
        if(s == t) return 0;
        for(const auto& d : deadends) st.insert(d);
        if(st.count(s)) return -1;
        int ans = bfs();
        return ans;
    }
    int bfs(){
        queue<string> d1,d2;
        unordered_map<string,int> m1,m2;
        d1.push(s); m1[s] = 0;
        d2.push(t); m2[t] = 0;
        while(d1.size() and d2.size()){
            int t = -1;
            if(d1.size() <= d2.size()){
                t = update(d1,m1,m2);
            }
            else{
                t = update(d2,m2,m1);
            }
            if(t != -1) return t;
        }
        return -1;
    }
    int update(queue<string>& q,unordered_map<string,int>& cur,unordered_map<string,int>& other){
        int m = q.size();
        while (m-- > 0) {
            string t = q.front(); q.pop();
            int step = cur[t];
            for(int i = 0; i < 4; i++){
                for(int j = -1; j <= 1; j++){
                    if(j == 0) continue;
                    int origin = t[i] - '0';
                    int next = (origin + j) % 10;
                    if(next == -1) next = 9;
                    string copy = t;
                    copy[i] = '0' + next;
                    if(st.count(copy) or cur.count(copy)) continue;
                    if(other.count(copy)) return step + 1 + other[copy];
                    else{
                        q.push(copy);
                        cur[copy] = step + 1;
                    }
                }
            }
        }
        return -1;
    }
};

// 作者：宫水三叶
// 链接：https://leetcode.cn/problems/open-the-lock/solutions/843986/gong-shui-san-xie-yi-ti-shuang-jie-shuan-wyr9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
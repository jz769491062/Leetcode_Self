class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        queue<int> q;
        // 注意编号1~n
        vector<int> inDegreeVec(n + 1);
        vector<unordered_set<int>> adjList(n + 1);
        for (vector<int>& v : relations) {
            adjList[v[0]].insert(v[1]);
            inDegreeVec[v[1]]++;
        }
        for (int i = 1; i < inDegreeVec.size(); i++) {
            if (inDegreeVec[i] == 0) {
                q.push(i);
            }
        }
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                for (int nei : adjList[curr]) {
                    inDegreeVec[nei]--;
                    if (inDegreeVec[nei] == 0) {
                        q.push(nei);
                    }
                }
            }
            res++;
        }
        for (int i : inDegreeVec) {
            if (i != 0) {
                return -1;
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/parallel-courses/description/
// https://leetcode.cn/problems/QA2IGt/
class Solution {
public:
    // 建立邻接表
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for (vector<int>& edge: prerequisites) {
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList = buildGraph(numCourses, prerequisites);
        // BFS基于入度，遍历结束后所有入度都是0就OK，否则有环
        vector<int> inDegree(numCourses);
        for (vector<int>& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            inDegree[to]++;
        }
        queue<int> myQ;
        // 入度为0的课程作为最开始上的课
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                myQ.push(i);
            }
        }
        vector<int> res(numCourses);
        int idx = 0;
        while (!myQ.empty()) {
            int currCourse = myQ.front();
            myQ.pop();
            res[idx] = currCourse;
            // 每遍历过一门课idx+1
            idx++;
            for (int neighbor : adjList[currCourse]) {
                // neighbor预置条件满足，入度减一
                inDegree[neighbor]--;
                // neighbor入度为0，意味着所有前置条件满足，可以上了
                // 如果有循环依赖的话，入度就无法减到0，也就直接不加入我们的queue遍历了
                // 事实上这个入度也帮助我们实现了类似DFS visited的功能, 入度为0才入队就不会死循环了
                if (inDegree[neighbor] == 0) {
                    myQ.push(neighbor);
                }
            }
        }
        // idx没到numCourses说明有的节点没有遍历，有环，没有上完所有课的办法
        if (idx != numCourses) {
            return {};
        }
        return res;
    }
};
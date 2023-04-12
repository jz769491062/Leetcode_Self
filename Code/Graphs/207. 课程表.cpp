class Solution {
public:
vector<bool> onPath;//记录递归栈中节点
vector<bool> visited;//防止回头路
bool hasCycle = false;//发现走了回头路就标记
    // 建立邻接表
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for (vector<int>& edge: prerequisites) {
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }

    void traverse(vector<vector<int>>& adjList, int index) {
        // 环出现了
        if (onPath[index]) {
            hasCycle = true;
            // 有环不必继续了
            return;
        }
        // 不走回头路
        if (visited[index]) {
            return;
        }
        // 记得visited, onpath都标记
        visited[index] = true;
        onPath[index] = true;
        for (int neighbor : adjList[index]) {
            traverse(adjList, neighbor);
        }
        // 记得只还原onPath不要还原visited
        onPath[index] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 如果有环，就无法修完全部课程，这题等于判断是否图里有环
        // 建立邻接表
        vector<vector<int>> adjList = buildGraph(numCourses, prerequisites);
        visited.resize(numCourses);
        onPath.resize(numCourses);
        for (int i = 0; i < numCourses; i++) {
            traverse(adjList, i);
        }
        return hasCycle == false; // 无环就可以完成全部课程
    }
};// https://leetcode.cn/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int>> adjList;
        for (vector<int>& v : prerequisites) {
            adjList[v[0]].insert(v[1]);
        }
        vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (dfs(adjList, visited, i)) {
                return false;
            }
        }
        return true;
    }

    bool dfs( unordered_map<int, set<int>>& adjList,  vector<int>& visited, int idx) {
        if (visited[idx] == 1) {
            return true;
        }
        if (visited[idx] == 2) {
            return false;
        }
        visited[idx] = 1;
        for (int neighbor : adjList[idx]) {
            if (dfs(adjList, visited, neighbor)) {
                return true;
            }
        }
        visited[idx] = 2;
        return false;
    }
};
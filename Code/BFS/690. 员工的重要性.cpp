/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> m;
        for (auto e : employees) {
            m[e->id] = e;
        }
        vector<bool> visited(2001);
        queue<Employee*> q;
        q.push(m[id]);
        visited[id] = true;
        int res = 0;
        while (!q.empty()) {
            Employee* curr = q.front();
            q.pop();
            res += curr->importance;
            for (int sub : curr->subordinates) {
                if (!visited[sub]) {
                    q.push(m[sub]);
                    visited[sub] = true;
                }
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/employee-importance/description/
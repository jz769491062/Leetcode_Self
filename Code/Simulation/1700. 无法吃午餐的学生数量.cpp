class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> stuCount(2);
        for (int type : students) {
            stuCount[type]++;
        }
        for (int s : sandwiches) {
            if (stuCount[s] == 0) {
                // 没有想要这种三明治的学生了，这时候才会死循环，return剩下的学生
                return stuCount[0] + stuCount[1];
            }
            stuCount[s]--; // 一个学生被满足，反正是个环早晚轮到对应的学生
        }
        return 0;
    }
};// https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/
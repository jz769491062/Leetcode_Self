class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> myStack;
        for (int i = n - 1; i >= 0; i--) {
            while(!myStack.empty() && temperatures[myStack.top()] <= temperatures[i]) {
                myStack.pop();
            }
            if (myStack.empty()) {
                res[i] = 0;
            } else {
                res[i] = myStack.top() - i;
            }
            myStack.push(i);
        }
        return res;
    }
};//https://leetcode.cn/problems/daily-temperatures/
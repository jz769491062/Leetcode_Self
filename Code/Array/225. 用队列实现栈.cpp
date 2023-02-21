class MyStack {
public:
int topEle;
queue<int> q;
    MyStack() {

    }
    
    void push(int x) {
        topEle = x;
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        while (size > 2) {
            // 留下队尾2个元素
            int temp = q.front();
            q.pop();
            q.push(temp);
            size--;
        }
        // 留2个为了保证topEle正确
        topEle = q.front();
        int temp = q.front();
        q.pop();
        q.push(temp);
        // 现在是真的pop掉
        temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return topEle;
    }
    
    bool empty() {
        return q.empty();
    }
};// https://leetcode.cn/problems/implement-stack-using-queues/description/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
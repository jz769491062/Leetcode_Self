class MyQueue {
    stack<int> s1, s2;
    // s1 队头，s2队尾
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        peek();// peek保证s2不为空
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    
    int peek() {
        // 元素转移到s2以找到队头
        if (s2.empty()) {
            while (!s1.empty()) {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};//https://leetcode.cn/problems/implement-queue-using-stacks/description/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
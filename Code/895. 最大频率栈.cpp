// https://leetcode.cn/problems/maximum-frequency-stack/description/
class FreqStack {
    int maxFreq = 0;
    unordered_map<int, int> valToFreq;
    // 如果频率最高的元素有多个，还得知道哪个是最近 push 进来的元素是哪个，所以需要freqToVals
    unordered_map<int, stack<int>> freqToVals; // 利用栈取出最近添加的元素
public:
    FreqStack() {

    }
    
    void push(int val) {
        // 获取最新的freq, map里的freq也+1
        int freq = valToFreq[val] + 1;
        valToFreq[val] = freq;
        // if key not in map yet create empty stack first
        freqToVals[freq].push(val);
        // 更新maxFreq
        maxFreq = max(freq, maxFreq);
    }
    
    int pop() {
        // 注意，从map里获取元素想操作的时候要使用reference &
        stack<int>& vals = freqToVals[maxFreq];
        int v = vals.top();
        vals.pop();
        // freq - 1
        int freq = valToFreq[v] - 1;
        valToFreq[v] = freq;
        // 更新maxFreq
        if (vals.empty()) {
            maxFreq--;
        }
        return v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
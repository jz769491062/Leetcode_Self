class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 如果要维护一个特定顺序，也不能打乱原先顺序的话，可以使用单调栈
        stack<char> stk;
        vector<int> countVec(256);//ASCII字符，统计字符出现次数
        for (int i = 0; i < s.size(); i++) {
            countVec[s[i]]++;
        }
        vector<bool> inStack(256);// 检查重复字符用
        for (char c: s) {
            // 遍历过就计数-1
            countVec[c]--;
            // 避免栈内重复
            if (inStack[c]) continue;
            // 经典单调栈维护手段
            // 保证栈顶元素不大于当前char，保证顺序前提下的最小化字典序
            // 或者说，我们找到了一个字典序更小的字符作为答案子串的开头
            while (!stk.empty() && c < stk.top()) {
                // 注意，现在栈顶的元素，之后也可能再也不会出现了，所以用countVec作为一个保险，确认后面还会不会出现
                // 也因此能保证在原字符串内的相对顺序
                if (countVec[stk.top()] == 0) {
                    // 栈顶这个字符已经是最后一个出现在字符串里的了，pop掉就缺失了这唯一的字符了，所以不做
                    break;
                }
                // 说明字符串后面还会出现这个栈顶的字符，那可以pop掉之前的了
                inStack[stk.top()] = false;
                stk.pop();
            }
            // 现在stk为空，或者stk顶部小于char，这已经是当前最小的字典序了，所以push
            stk.push(c);
            inStack[c] = true;
        }
        // 我们单调栈顶是字典序的末尾，所以拿出来后颠倒一下
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
}; // https://leetcode.cn/problems/remove-duplicate-letters/description/ 1081和这道题一样
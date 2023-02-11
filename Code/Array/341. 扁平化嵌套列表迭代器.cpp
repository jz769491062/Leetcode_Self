// https://mp.weixin.qq.com/s/uEmD5YVGG5LHQEmJQ2GSfw
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:

    NestedIterator(vector<NestedInteger> &nestedList) {
        // 可以当做是一棵N叉树！
        stk.emplace(nestedList.begin(), nestedList.end());
    }
    
    int next() {
        // 由于保证调用 next 之前会调用 hasNext，直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
        return stk.top().first++->getInteger();
    }
    
    bool hasNext() {
        while (!stk.empty()) {
            auto& p = stk.top();
            if (p.first == p.second) {
                stk.pop();
                continue;
            }
            if (p.first->isInteger()) {
                return true;
            }
            // 如果当前元素是列表，则入栈，迭代器指向下一个元素
            auto& lst = p.first->getList();
            p.first++;
            stk.emplace(lst.begin(), lst.end());
        }
        return false;
    }
private:
    // pair 中存储的是列表的当前遍历位置，以及一个尾后迭代器用于判断是否遍历到了列表末尾
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
};// https://leetcode.cn/problems/flatten-nested-list-iterator/
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
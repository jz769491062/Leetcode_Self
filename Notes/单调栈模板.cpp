vector<int> NextGreaterElement(vector<int>& nums) {
    vector<int> greater(nums.size());
    stack<int> s;
    // 单调栈模板
    for (int i = nums.size() - 1; i >= 0; i--) {
        // 单调栈底部元素大，顶部元素小
        // 然后维持这个底部到顶部依次变小的顺序
        while (!s.empty() && nums[i] >= s.top()) {
            s.pop();
        }
        // 这样子，还留在栈里的元素必然是大于当前元素的
        // 再加上是倒着数组遍历，单调栈元素也是按照数组倒序入栈，所以留在栈顶的就是最近的那个更大元素
        greater[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return greater;
}

可以直接把之前单调栈计算过的结果保存进栈，stack<pair<int, int>>这样。
901. 股票价格跨度
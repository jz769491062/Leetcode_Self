class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> result(n);
        // 解决循环数组问题技巧；把数组长度翻倍，然后求模获得循环后的长度
        for(int i = n * 2 - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i % n] >= stk.top()) {
                stk.pop();
            }
            result[i % n] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i % n]);
        }
        return result;
    }
};//https://leetcode.cn/problems/next-greater-element-ii/description/
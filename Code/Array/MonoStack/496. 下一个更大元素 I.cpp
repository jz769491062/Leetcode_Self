class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> greater = NextGreaterElement(nums2);
        unordered_map<int, int> valToGreater;// 值->下个最大元素的值
        for (int i = 0; i < nums2.size(); i++) {
            valToGreater[nums2[i]] = greater[i];
        }
        // nums1是nums2的子集，所以可以利用Map得到结果
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = valToGreater[nums1[i]];
        }
        return res;
    }

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
};// https://leetcode.cn/problems/next-greater-element-i/description/
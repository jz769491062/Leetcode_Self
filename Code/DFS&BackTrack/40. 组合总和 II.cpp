#include <numeric>

class Solution {
public:
vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr) {
        int currSum = std::accumulate(curr.begin(), curr.end(), 0);
        if (currSum == target) {
            res.push_back(curr);
            return;
        }
        if (currSum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            // 如何区分同数字不同元素？比较当前元素和前一个元素值是否相同。
            // 值已经相同了，只遍历一条即可，不用再重复重头遍历其他该数字开头的路径了
            // 如果不做这个剪枝，就会导致重复的结果输出，比如有2个1，然后结果就会有2个一样的[1,7]，分别源自2个不同的1元素
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, curr);//不可复选元素，所以i + 1
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());//数字可重复，元素不可重复时，sort来区分同数字的不同元素
        backtrack(candidates, target, 0, curr);
        return res;
    }
};//https://leetcode.cn/problems/combination-sum-ii/description/
class Solution {
public:
vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& currRes, int currIndex) {
        res.push_back(currRes);//子集问题，直接pushback进res就行
        //使用currIndex和+1，利用数组顺序保证自己不重复
        for (int i = currIndex; i < nums.size(); i++) {
            currRes.push_back(nums[i]);
            backtrack(nums, currRes, i + 1);
            currRes.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currRes;
        backtrack(nums, currRes, 0);
        return res;
    }
};//https://leetcode.cn/problems/subsets/
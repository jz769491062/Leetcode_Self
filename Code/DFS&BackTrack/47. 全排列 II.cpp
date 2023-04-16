class Solution {
public:
// 如果不使用used数组，进入分支后分支会认为所有数字依然都能选，导致元素重复选择，错误。
// 比如[0,1]，如果不用used数组，还会输出[0,0], [1,1]错误答案
vector<bool> used;
vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& curr) {
        // 这里只检查size意味着剪枝要在下面for loop进行
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            // 注意是检查used[i - 1]而不是used[i]!这样才能确保我们剪掉的是那个多余的支
            // 比如现在[1,1,2]，在第二个1的时候，如果第一个1已经使用了那没有问题的，但是第一个1还没使用的话意味着这是重复分支的开始，直接干掉这个重复的分支
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums,curr);
            used[i] = false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        used.resize(nums.size()); //记得初始化used数组大小
        sort(nums.begin(), nums.end()); // sort，然后判断是否遭遇了同数字的不同元素，然后剪枝
        backtrack(nums, curr); // 排列可能选到之前靠前的数字，所以不要用start来控制！就从index0开始！
        return res;
    }
};// https://leetcode.cn/problems/permutations-ii/description/
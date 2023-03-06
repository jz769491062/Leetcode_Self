class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        int n = nums.size();
        vector<int> copy = nums;
        for (int i = 0; i < n; i++) {
            // 洗牌算法
            // 生成一个 [i, n-1] 区间内的随机数
            // 为啥这样打乱能让所有排列变成等可能的？
            // 等可能意味着总共要有N!种排列
            // 因为对于copy[0]，有n种可能性；copy[1]有n-1种可能性……这样最后总共可以生成n!种排列
            int r = i + rand() % (n - i);
            swap(copy[i], copy[r]);
        }
        return copy;
    }
};// https://leetcode.cn/problems/shuffle-an-array/description/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
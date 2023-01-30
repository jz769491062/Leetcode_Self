class NumArray {
public:
vector<int> preSum;// preSum[i]表示0...i-1加起来的和
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size() + 1); // 注意前缀和size+1，第一位空出
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // right + 1代表0~right, left代表0~left-1，一减去正好是left~right之间的结果
        return preSum[right + 1] - preSum[left];
    }
};
// https://leetcode.cn/problems/range-sum-query-immutable/description/
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
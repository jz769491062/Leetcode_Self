class Solution {
public:
//因为我们只能减小数字，所以我们只有让减小 奇数/偶数位置 使其比其两侧小，选择两者中更优的即可
    int movesToMakeZigzag(vector<int>& nums) {
        int ans = INT_MAX, s = 0, n = nums.size();
        for(int offset : {0, 1}){
            s = 0;
            for(int i = offset; i < n; i += 2)
            // 左邻居存在，计算需要下降的最大区间
                s += max({  i>0 ? nums[i] - nums[i-1] + 1 : 0, 
                // 右邻居存在，计算需要下降的最大区间
                            i+1<n ? nums[i] - nums[i+1] + 1 : 0, 
                            0});
            ans = min(ans, s);
        }
        return ans;
    }
};// https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/description/
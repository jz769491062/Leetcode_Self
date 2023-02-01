// https://leetcode.cn/problems/random-pick-with-weight/
class Solution {
public:
vector<int> preSum;
    Solution(vector<int>& w) {
        // 可以根据weight开一个类似前缀和的数组，随机数在那个区间就返回其区间对应的下标
        preSum.resize(w.size() + 1);
        preSum[0] = 0;
        int currSum = 0;
        // 构造前缀和
        for (int i = 0; i < w.size(); i++) {
            currSum += w[i];
            preSum[i + 1] = currSum;
        }
    }

    int leftBound(vector<int>&nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1; // +1以触发右侧边界向左收敛
            } else if (nums[mid] > target) {
                right = mid;
            }
        }
        return left;
    }
    
    int pickIndex() {
        // 现在[1, currSum或preSum[n-1]]就是我们随机数的取值范围
        int n = preSum.size();
        // 前缀和的[0]就是0，是个摆设，所以从[1]开始才是我们关心的取值范围
        int randNum = rand() % preSum[n - 1] + 1;
        // 获得随机数后，我们需要找大于等于这个数字的最左边界，那就是left_bound
        // 最后还要对索引-1，因为前缀和数组有1位索引偏移，[0]是前缀和里占位用的，但是0依然是一个可能的结果
        int idx = leftBound(preSum, randNum) - 1;
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
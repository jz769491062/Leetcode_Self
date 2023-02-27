// https://leetcode.cn/problems/sliding-window-maximum/description/
// 整体复杂度O(N), 空间O(k)
class Solution {
public:
    class MonoQueue {
    public:
        deque<int> q;
        // 单调队列，push一路往前干掉元素，直到遇到比自己大的停下
        void pushVal(int val) {
            while (!q.empty() && q.back() < val) {
                q.pop_back();
            }
            q.push_back(val);
        }

        int getMax() {
            return q.front();
        }
        // 注意：之所以要判断data.front() == n，是因为我们想删除的队头元素n可能已经被「压扁」了，可能已经不存在了，所以这时候就不用删除了
        void popVal(int n) {
            if (n == q.front()) {
                q.pop_front();
            }
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonoQueue window;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                // 先填满k-1个窗口位置，然后再开始不断更新窗口
                window.pushVal(nums[i]);
            } else {
                // 更新窗口
                window.pushVal(nums[i]);
                res.push_back(window.getMax());
                window.popVal(nums[i - k + 1]);
            }
        }
        return res;
    }
};
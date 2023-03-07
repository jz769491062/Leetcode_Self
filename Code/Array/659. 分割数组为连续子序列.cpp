class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // 题目数组已经排好序了
        // 每一个数字有两种选择：1 以自己开头创建子序列 2 接到已有的子序列后面，尽量接到其他子序列后面
        // 当前每个元素还剩下的次数
        unordered_map<int, int> freq;
        // 记录可以接几个该数字到当前已经形成的子序列后面
        unordered_map<int, int> need;
        for (int n : nums) {
            freq[n]++;
        }
        for (int n : nums) {
            if (freq[n] == 0) {
                // 这数字已经被子序列用完了，跳过
                continue;
            }
            // 先判断能不能用于其他子序列
            if (need.count(n) && need[n] > 0) {
                freq[n]--;
                need[n]--;
                need[n + 1]++;
            }
            // 然后判断能否以这个数字为开头生成子序列
            else if (freq[n] > 0 && freq[n + 1] > 0 &&freq[n + 2] > 0) {
                freq[n]--;
                freq[n + 1]--;
                freq[n + 2]--;
                need[n + 3]++;
            } else {
                return false; // 完全用不了这个数字，false
            }
        }
        return true;
    }
};// https://leetcode.cn/problems/split-array-into-consecutive-subsequences/description/
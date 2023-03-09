class Solution {
public:
    int leftBound(vector<int>& arr, int target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                r = mid;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else if (arr[mid] > target) {
                r = mid;
            }
        }
        // 注意如果没找到结果的话，就是l走到了头
        if (l == arr.size()) {
            return -1;
        }
        // 注意return的是l，尽管我们不断缩短r右边界
        return l;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        // 改良：在找下一个匹配的char时，对后面的区间直接上二分搜索，而不是线性遍历
        // 预处理一波，记录下每个char出现的索引, 然后对这些索引二分搜索，就很快
        unordered_map<char, vector<int>> charToIdx;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            charToIdx[c].push_back(i);
        }
        int res = 0;
        for (string w : words) {
            int wPointer = 0;
            int sPointer = 0;
            for (; wPointer < w.size(); wPointer++) {
                char c = w[wPointer];
                if (!charToIdx.count(c)) {
                    break; // char甚至不是s的一部分，肯定不是子序列
                }
                // 尽量在s里找最靠左匹配这个char的位置
                int pos = leftBound(charToIdx[c], sPointer);
                if (pos == -1) {
                    break;
                }
                // 找到了，接下来可以找下一个字符的匹配位置了
                sPointer = charToIdx[c][pos] + 1;
            }
            // word的char都匹配了s，是子序列
            if (wPointer == w.size()) {
                res++;
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/number-of-matching-subsequences/description/
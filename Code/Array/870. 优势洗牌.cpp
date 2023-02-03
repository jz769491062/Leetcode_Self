class Solution {
public:
    class PairComparator {
    public:
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            // 相等的值是返回false的
            // 注意，在comparator里，lhs<rhs是std::less 降序最大堆， lhs>rhs 是std::greater升序最小堆
            // less表示堆排从小到大排序，是大根堆，所以值大的优先出
            // 和sort 里 std::greater, less正好反过来
            // sort里 std::greater()(a > b是否true)是降序，std::less()(a < b是否true)是升序
            return p1.first < p2.first;
            
        }
    };
    
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // 田忌赛马：排序，能赢就上，不能赢换垫底的
        priority_queue<pair<int, int>, vector<pair<int, int>>, PairComparator> pq; // 降序排列齐王的<最大堆
        int n = nums1.size();
        vector<int> res(n);
        for (int i = 0; i < nums2.size(); i++) {
            pq.push({nums2[i], i});
        }
        // 注意！sort里 std::greater()(a > b是否true)是降序，std::less()(a < b是否true)是升序！
        sort(nums1.begin(), nums1.end(), std::greater<int>());// 此题选择降序排列田忌的
        cout << nums1[0] << endl;
        int left = 0, right = n - 1;
        while (!pq.empty()) {
            int curr1 = nums1[left];
            int curr2 = pq.top().first;
            // cout << curr1 << endl;
            // cout << curr2 << endl;
            int curr2Idx = pq.top().second;
            pq.pop();
            if (curr1 > curr2) {
                res[curr2Idx] = curr1;
                left++;
            } else {
                res[curr2Idx] = nums1[right];
                right--;
            }
        }
        return res;
    }
}; // https://leetcode.cn/problems/advantage-shuffle/description/
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) -> bool {
            int p = pills;
            multiset<int> workerSet; // 有序集合
            // 尽量挑力量大的工人
            for (int i = m - mid; i < m; i++) {
                workerSet.insert(workers[i]);
            }
            // 枚举任务，从大到小
            for (int i = mid - 1; i >= 0; i--) {
                // 不需要药丸就能拿下
                if (auto it = prev(workerSet.end()); *it >= tasks[i]) {
                    workerSet.erase(it);
                } else {
                    // 需要药丸的情况
                    // 但是药丸用完了，false
                    if (p == 0) {
                        return false;
                    }
                    // 还有药丸，就尽量找一个正好用药丸能拿动的工人
                    auto fit = workerSet.lower_bound(tasks[i] - strength);
                    // 有药丸也找不到能拿动的工人,false
                    if (fit == workerSet.end()) {
                        return false;
                    }
                    // 使用药丸，并搬运
                    p--;
                    workerSet.erase(fit);
                }
            }
            return true;
        };
        // 二分搜索，尝试完成mid前所有任务。能完成Mid，那mid之前的都能完成。
        int left = 0, right = min(m, n), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;
                // 尝试多完成一些任务（更繁重的）
                left = mid + 1;
            } else {
                // 减轻任务，以保证任务可完成
                right = mid - 1;
            }
        }
        return ans;
    }
};// https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/description/?company_slug=huawei
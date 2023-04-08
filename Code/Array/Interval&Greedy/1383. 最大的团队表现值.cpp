class Solution {
public:
    struct Engineer {
        int speed;
        int eff;
        // 只能overload <，对于std::less
        bool operator < (const Engineer& rhs) const {
            return this->speed > rhs.speed;
        }
    };

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // 有两个变化量。不妨定一个，动一个，这样就有入手空间了
        // 枚举效率的最小值，然后找k-1个效率不低于的，再最大化速度
        // 在所有效率大于等于e_{min}的工程师中选取不超过k-1个
        // 保证eff有序后，用pq内的值最大化速度
        // pq里默认大顶堆std::less, 小顶堆是std::greater
        priority_queue<Engineer> pq;
        vector<Engineer> v;
        for (int i = 0; i < n; i++) {
            v.push_back({speed[i], efficiency[i]});
        }
        // 从大到小按效率排，这样遍历的时候能保留尽量大的效率值
        sort(v.begin(), v.end(), [] (const Engineer& l, const Engineer& r){ return l.eff > r. eff;});
        long long ans = 0;
        // 利用speedSum变量，保存k-1个工程师最大速度的和，然后每次pq满了就踢出一个最小的
        long long speedSum = 0;
        for (int i = 0; i < n; i++) {
            // cout << v[i].eff << " " << v[i].speed << endl;
            // 相对于前面的元素，minE就是现在最小的效率
            // 然后speedSum考虑的都是大于等于当前minE的工程师，排好序了
            long long minE = v[i].eff;
            speedSum += v[i].speed;
            // cout << "speedSum: " << speedSum <<endl;
            // cout << "product: " << minE * speedSum <<endl;
            ans = max(ans, minE * speedSum);
            pq.push(v[i]);
            if (pq.size() == k) {
                // cout << "pqtop" << pq.top().speed << endl;
                // 干掉一个速度最慢的，以求速度最大化
                speedSum -= pq.top().speed;
                pq.pop();
            }
        }
        return ans % ((int(pow(10, 9)) + 7));
    }
};// https://leetcode.cn/problems/maximum-performance-of-a-team/description/?company_slug=huawei
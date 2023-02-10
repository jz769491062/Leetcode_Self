class Solution {
public:
    // struct Pair {
    //     int first;
    //     int second;
    //     Pair& operator=(Pair other)
    //     {
    //         first = other.first;
    //         second = other.second;
    //         return *this;
    //     }
    // };
vector<pair<int,int>> tempVec;// 归并排序的辅助数组，不用map是因为我们需要pair的索引排序时进行对应
vector<int> res;
    void merge(vector<pair<int,int>>& valToIdxVec, int start, int mid, int finish) {
        for (int i = start; i <= finish; i++) {
            tempVec[i] = valToIdxVec[i];// 复制一份用于比较
        }
        // 双指针合并数组
        int leftHalfIdx = start, rightHalfIdx = mid + 1;
        for (int i = start; i <= finish; i++) {
            if (leftHalfIdx == mid + 1) {
                valToIdxVec[i] = tempVec[rightHalfIdx];
                rightHalfIdx++;
            }
            // 在归并排序的基础上，在更新左半边的时候，也更新更小元素数量
            // 为什么是左半边才更新？因为我们只关心右半边那些比左半边当前数字小的情况，右半边比左大的时候,就是检查之前右半边有多少个比左边数字小的时候了
            else if (rightHalfIdx == finish + 1) {
                valToIdxVec[i] = tempVec[leftHalfIdx];
                leftHalfIdx++;
                res[valToIdxVec[i].second] += rightHalfIdx - mid - 1; // [mid + 1, rightHalfIdx)
            }
            // 比大小
            // 在归并排序的基础上，在更新左半边的时候，也更新更小元素数量
            // 比大小的时候记得break tie, 注意这里必须用<=break tie，否则[-1,-1]用例过不了
            else if (tempVec[leftHalfIdx].first <= tempVec[rightHalfIdx].first) {
                valToIdxVec[i] = tempVec[leftHalfIdx];
                leftHalfIdx++;
                res[valToIdxVec[i].second] += rightHalfIdx - mid - 1; // [mid + 1, rightHalfIdx)
            }
            else {
                valToIdxVec[i] = tempVec[rightHalfIdx];
                rightHalfIdx++;
            }
        }
    }

    void mSort(vector<pair<int,int>>& valToIdxVec, int start, int finish) {
        if (start == finish) return;
        int mid = start + (finish - start) / 2;
        mSort(valToIdxVec, start, mid);
        mSort(valToIdxVec, mid + 1, finish);
        // 可以理解为二叉树后序
        merge(valToIdxVec, start, mid, finish);
    }

    vector<int> countSmaller(vector<int>& nums) {
        // 这道题其实可以利用归并排序的merge函数!
        // 因为merge双指针排序的时候，我们可以算[mid + 1, j)这个区间大小，就知道nums[mid]后面多少个数比它小了
        // 每次对nums赋值的时候，就是更小元素数量更新的时候
        int n = nums.size(); // 使用int，才能避免nums.size() - 1的underflow风险！不只是代码风格问题。
        tempVec.resize(n);
        res.resize(n);
        vector<pair<int,int>> valToIdxVec;
        // 注意如果没有resize好就赋值，会得到reference binding to null pointer of type错误
        valToIdxVec.resize(n);
        for (int i = 0; i < n; i++) {
            valToIdxVec[i] = {nums[i], i};
        }
        mSort(valToIdxVec, 0, n - 1);
        return res;
    }
};//https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/
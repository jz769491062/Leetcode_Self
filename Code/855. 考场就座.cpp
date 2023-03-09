int n;
// distance函数需要用到n，所以还是挪到全局域，确保MyComp不会有call to non-static member function without an object argument之类的头疼问题
int distance(const pair<int, int>& intv) {
    int x = intv.first;
    int y = intv.second;
    if (x == -1) return y; // 注意这两行return一定要是这个值，不能+1
    if (y == n) return n - x - 1;
    // 中点和端点之间的长度
    return (y - x) / 2;
}

struct MyComp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // 注意注意！不能简单地让它计算一个线段两个端点间的长度，而是让它计算该线段中点和端点之间的长度
        // 这样[0,4] 和 [4,9] 的 distance 值就相等了，算法会比较二者的索引，取较小的线段进行分割
        int distA = distance(a);
        int distB = distance(b);
        if (distA == distB) {
            // 座位号小的优选
            return a.first < b.first;
        }
        // 从大到小排线段长度
        return distA > distB;
    }
};

class ExamRoom {
    // 端点p -> 左/右端点为p的线段
    map<int, pair<int, int>> left, right;

    void removeInterval(pair<int, int>& intv) {
        s.erase(intv);
        left.erase(intv.first);
        right.erase(intv.second);
    }

    void addInterval(pair<int, int>& intv) {
        s.insert(intv);
        left[intv.first] = intv;
        right[intv.second] = intv;
    }
public:
    // 我们需要能删除任意一个值而不只是最大的值，所以不能用priority_queue而是set
    set<pair<int, int>, MyComp> s;

    ExamRoom(int N) {
        n = N;
        // 虚拟线段，相当于标记座位的范围
        s.insert({- 1, n});
    }
    
    int seat() {
        pair<int, int> longest = *s.begin();
        int l = longest.first, r = longest.second;
        int seat;
        if (l == -1) {
            seat = 0;
        } else if (r == n) {
            seat = n - 1;
        } else {
            seat = l + (r - l) / 2;
        }
        // 然后创造新线段，删除老线段
        pair<int, int> nl = {seat, r}, nr = {l, seat};
        removeInterval(longest);
        addInterval(nl);
        addInterval(nr);
        return seat;
    }
    
    void leave(int p) {
        pair<int, int> leftHalf = right[p], rightHalf = left[p];
        // 合并线段
        pair<int, int> merged = {leftHalf.first, rightHalf.second};
        removeInterval(leftHalf);
        removeInterval(rightHalf);
        addInterval(merged);
    }
};
// https://leetcode.cn/problems/exam-room/description/
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
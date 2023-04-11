/* 二叉堆，下沉sink, 上浮swim
用于堆排序和优先级队列
二叉堆在逻辑上其实是一种特殊的二叉树（完全二叉树），只不过存储在数组里，通过简单运算即可得到子节点
最大堆/最小堆：每个父节点大于等于（小于等于）它的2个子节点。最大堆arr[1]是最大元素，最小堆arr[1]是最小元素

对于最大堆，会破坏堆性质的有两种情况：
1、如果某个节点 A 比它的子节点（中的一个）小，那么 A 就不配做父节点，应该下去，下面那个更大的节点上来做父节点，这就是对 A 进行下沉。
2、如果某个节点 A 比它的父节点大，那么 A 不应该做子节点，应该把父节点换下来，自己去做父节点，这就是对 A 的上浮。
当然，错位的节点 A 可能要上浮（或下沉）很多次，才能到达正确的位置，恢复堆的性质。所以代码中肯定有一个 while 循环。
我们只从堆底或者堆顶处理，所以上浮和下沉都需要
*/
template <class Key>
class MaxPQ {
public:
    MaxPQ(int cap) {
        pq.resize(cap + 1);// +1方便索引公式计算
    }

    Key max() {
        return pq[1];
    }

    void insert(Key e) {
        size++;
        // 先把新元素加到最后
        pq[size] = e;
        // 然后让它上浮到正确的位置
        swim(size);
    }
    /* 删除并返回当前队列中最大元素 */
    // 先把堆顶元素 A 和堆底最后的元素 B 对调，然后删除 A，最后让 B 下沉到正确位置
    Key delMax() {
        // 最大堆的堆顶就是最大元素
        Key max = pq[1];
        // 把这个最大元素换到最后，删除之
        swap(1, size);
        pq[size] = NULL;
        size--;
        // 让 pq[1] 下沉到正确位置
        sink(1);
        return max;
    }
private:
    vector<Key> pq;
    int size = 0;
    // 下沉第x个元素以维持最大堆
    // 如果 A 不是最大的就需要调整位置，要把较大的那个子节点和 A 交换。
    void sink(int x) {
        while (left(x) <= size) {
            // 先假设左边节点较大
            int max = left(x);
            // 如果右边节点存在，比一下大小
            if (right(x) <= size && less(max, right(x)))
                max = right(x);
            // 结点 x 比俩孩子都大，就不必下沉了
            if (less(max, x)) break;
            // 否则，不符合最大堆的结构，下沉 x 结点
            swap(x, max);
            x = max;
        }
    }
    // 上浮第x个元素以维持最大堆
    void swim(int x) {
        // 如果浮到堆顶，就不能再上浮了
        while (x > 1 && less(parent(x), x)) {
            // 如果第 x 个元素比上层大
            // 将 x 换上去
            swap(parent(x), x);
            x = parent(x);
        }
    }

    void swap(int i, int j) {
        Key temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }

    bool less(int i, int j) {
        return pq[i] < pq[j];
    }

    int left(int idx) {
        return idx * 2;
    }

    int right(int idx) {
        return idx * 2 + 1;
    }

    int parent(int idx) {
        return idx / 2;
    }
};
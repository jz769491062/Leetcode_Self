// https://leetcode.cn/problems/lru-cache/
class LRUCache {
public:
// 首先，需要cache有按照时序排序
// 其次，访问cache的某个key时要能够把它提到首位，也就是需要任何位置插入删除
// 哈希查找快但无序，链表有序插入删除快但查找慢。
// 合二为一：哈希链表，用哈希映射key实现快速查找，剩下的利用链表的性质
    // 一个节点
    class Node {
    public:
        int key, val;
        Node* prev, * next;
        Node(int k, int v) {
            key = k;
            val = v;
        }
    };
    // 一个双链表
    // 删除一个节点不光要得到该节点本身的指针，也需要操作其前驱节点的指针，而双向链表才能支持直接查找前驱，保证操作的时间复杂度 O(1)
    class DoubleLinkedList {
    private:
        Node* head, * tail;
        int size;
    public:
        DoubleLinkedList() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        // 都是 O(1)
        void addLast(Node* n) {
            // 修改tail->prev和n的两个指针
            n->prev = tail->prev;
            n->next = tail;
            tail->prev->next = n;
            tail->prev = n;
            size++;
        }

        void remove(Node* n) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            size--;
        }

        // 删除第一个节点并且返回这个节点，用于删除LRU元素
        // 我们链表头部是LRU，尾部是最近使用的
        Node* removeFirst() {
            if (head->next == tail) return NULL;
            Node* first = head->next;
            remove(first);
            return first;
        }

        int Size() {return size;}
    };
    // 写好了双链表，就可以和哈希搭配实现了
private:
    unordered_map<int, Node*> nodeMap;
    DoubleLinkedList cache;
    int capacity;
    // 对于cache我们有4个直接操作hashmap的操作：
    // 提升到最近使用，加入cache(最近使用的位置)，删除某个key，删除LRU元素
    void makeRecent(int key) {
        Node* x = nodeMap[key]; // 注意用一个变量来捕捉nodeMap结果，让下面操作都能准确引用指针
        //先删除，然后插入队尾
        cache.remove(x);
        cache.addLast(x);
    }

    void addRecent(int key, int val) {
        Node* x = new Node(key, val);
        cache.addLast(x);
        // 记得nodeMap也加映射
        nodeMap[key] = x;
    }

    void deleteKey(int key) {
        Node* x = nodeMap[key];
        cache.remove(x);
        // 记得nodeMap也删除映射
        nodeMap.erase(key);
    }

    void deleteLRU() {
        Node* toDelete = cache.removeFirst();
        // removeFirst返回这个节点，就是为了能让我们哈希链表也删除Map对应的映射
        int delKey = toDelete->key;
        nodeMap.erase(delKey);
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) return -1;//没有这个元素
        // 执行get的同时，我们也把这个key提升成最近使用过的
        makeRecent(key);
        return nodeMap[key]->val;
    }
    
    void put(int key, int value) {
        // 更新的case: 变更数据值value也会导致元素变成最新使用的, 所以也是删除再插入
        if (nodeMap.find(key) != nodeMap.end()) {
            deleteKey(key);
            addRecent(key, value);
            return;//注意这里就返回了
        }
        // 数量超过逐出: 添加前先看看是不是已经满了
        if (cache.Size() == capacity) {
            deleteLRU();
        }
        // 元素不存在需要插入的case
        addRecent(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
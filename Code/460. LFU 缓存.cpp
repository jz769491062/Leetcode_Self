class LFUCache {
public:
    struct Node {
        int key, val, freq;
        Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
    };

    LFUCache(int capacity) {
        minFreq = 0;
        this->capacity = capacity;
    }
    // 新元素在begin, 旧元素在end
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()) return -1;
        list<Node>::iterator node = it->second;
        int val = node -> val, freq = node -> freq;
        // 插入freq+1的key前，删除freq的对应node
        freqTable[freq].erase(node);
        if (freqTable[freq].size() == 0) {
            // 如果list已经空，删除键值对
            freqTable.erase(freq);
            // 注意，没有元素是这个freq的话，也要修改minFreq了
            if (minFreq == freq) minFreq += 1;
        }
        // 插入freq+1
        freqTable[freq + 1].push_front(Node(key, val, freq + 1));
        keyToNode[key] = freqTable[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()) {
            // 需要新加
            // 先检查下capacity
            if (capacity == keyToNode.size()) {
                //删除LFU
                auto itD = freqTable[minFreq].back();
                keyToNode.erase(itD.key);
                // 注意顺序，先对keyToNode进行删除再删除freqTable，确保iterator不乱
                freqTable[minFreq].pop_back();
                if (freqTable[minFreq].size() == 0) {
                    // 如果list已经空，删除键值对
                    freqTable.erase(minFreq);
                }
            }
            // 然后插入新元素
            freqTable[1].push_front(Node(key, value, 1));
            keyToNode[key] = freqTable[1].begin();
            minFreq = 1;
        } else {
            // 更新值即可, 类似get
            list<Node>::iterator node = it->second;
            int freq = node -> freq;
            // 插入freq+1的key前，删除freq的对应node
            freqTable[freq].erase(node);
            if (freqTable[freq].size() == 0) {
                // 如果list已经空，删除键值对
                freqTable.erase(freq);
                // 注意，没有元素是这个freq的话，也要修改minFreq了
                if (minFreq == freq) minFreq += 1;
            }
            // 插入freq+1
            freqTable[freq + 1].push_front(Node(key, value, freq + 1));
            keyToNode[key] = freqTable[freq + 1].begin();
        }
    }
private:
    unordered_map<int, list<Node>::iterator> keyToNode; // 注意用iterator遍历同freq对应的各个Node
    unordered_map<int, list<Node>> freqTable;
    int minFreq, capacity;
};
// https://leetcode.cn/problems/lfu-cache/description/
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
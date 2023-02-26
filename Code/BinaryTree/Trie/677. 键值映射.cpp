//https://leetcode.cn/problems/map-sum-pairs/description/
class MapSum {
public:
unordered_map<string, int> trieMap;
    MapSum() {
        trieMap.clear();
    }
    
    void insert(string key, int val) {
        trieMap[key] = val;
    }
    
    int sum(string prefix) {
        int val = 0;
        for (auto it = trieMap.begin(); it != trieMap.end(); it++) {
            // 可以利用string的find函数找前缀，有前缀则返回结果是0
            if (it->first.find(prefix) == 0) {
                val += it->second;
            }
        }
        return val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
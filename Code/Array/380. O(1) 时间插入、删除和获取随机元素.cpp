class RandomizedSet {
public:
    // 存储元素的值
    vector<int> nums;
    // 记录每个元素对应在 nums 中的索引，value-index
    unordered_map<int,int> valToIndex;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        // 若 val 已存在，不用再插入
        if (valToIndex.count(val)) {
            return false;
        }
        // 若 val 不存在，插入到 nums 尾部，
        // 并记录 val 对应的索引值
        valToIndex[val] = nums.size();// 注意这个size是pushback前的所以不用-1
        nums.push_back(val);
        return true;
    }
    // O(1)删除：把元素交换到尾部然后pop
    bool remove(int val) {
        if (!valToIndex.count(val)) return false;
        int idx = valToIndex[val];
        valToIndex[nums.back()] = idx;// 交换对应的索引
        swap(nums[idx], nums.back());// 交换实际数字位置
        // 然后可以删除对应的索引和实际的数字
        valToIndex.erase(val);
        nums.pop_back();
        return true;
    }
    // 等概率O(1)随机获取，那数组是不可避免了，因为hash概率终究不相等
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */ // https://leetcode.cn/problems/insert-delete-getrandom-o1/description/
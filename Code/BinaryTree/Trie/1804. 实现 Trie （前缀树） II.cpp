class Trie { // https://leetcode.cn/problems/implement-trie-ii-prefix-tree/description/
public:
unordered_map<string, int> trieMap;
    Trie() {
        trieMap.clear();
    }
    
    void insert(string word) {
        trieMap[word]++;
    }
    
    int countWordsEqualTo(string word) {
        if (trieMap.count(word)) {
            return trieMap[word];
        }
        return 0;
    }
    
    int countWordsStartingWith(string prefix) {
        int count = 0;
        for (unordered_map<string, int>::iterator it = trieMap.begin(); it != trieMap.end(); it++) {
            // 可以利用string的find函数找前缀，有前缀则返回结果是0
            if (it->first.find(prefix) == 0) {
                count += it->second;
            }
        }
        return count;
    }
    
    void erase(string word) {
        trieMap[word]--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
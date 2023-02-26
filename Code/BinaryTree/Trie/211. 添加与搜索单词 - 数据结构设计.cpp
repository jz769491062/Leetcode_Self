class WordDictionary {// https://leetcode.cn/problems/design-add-and-search-words-data-structure/
public:
    template <class V>
class TrieMap
{
public:
    struct TrieNode
    {
        V val = NULL;
        vector<TrieNode *> children;
        TrieNode()
        {
            children.resize(26);
        }
    };
    /***** 增/改 *****/
    // 在 Map 中添加 key
    void put(string key, V val)
    {
        if (!containsKey(key))
        {
            // 新增键值对
            size++;
        } else {
            return;
        }
        // 需要一个额外的辅助函数，并接收其返回值
        root = putHelper(root, key, val, NULL);
    }

    /***** 查 *****/
    // 搜索 key 对应的值，不存在则返回 NULL
    // get("the") -> 4
    // get("tha") -> NULL
    V get(string key)
    {
        TrieNode *x = getNode(root, key);
        if (x == NULL || x->val == NULL)
        {
            return NULL; // 注意x的val也要检查,才能保证Key真的存在
        }
        return x->val;
    }

    // 判断 key 是否存在在 Map 中
    // containsKey("tea") -> false
    // containsKey("team") -> true
    bool containsKey(string key)
    {
        return get(key) != NULL;
    }

    // 通配符 . 匹配任意字符，判断是否存在匹配的键
    // hasKeyWithPattern(".ip") -> true
    // hasKeyWithPattern(".i") -> false
    bool hasKeyWithPattern(string pattern)
    {
        return hasKeyWithPatternHelper(root, pattern, NULL);
    }

    // 返回 Map 中键值对的数量
    int Size()
    {
        return this->size;
    }

private:
    // ASCII 码个数
    const static int R = 256;
    // 当前存在 Map 中的键值对个数
    int size = 0;

    // Trie 树的根节点
    TrieNode *root = NULL;
    TrieNode *getNode(TrieNode *node, string key)
    {
        TrieNode *p = node;
        for (int i = 0; i < key.size(); i++)
        {
            // 检查NULL
            if (!p)
                return NULL;
            // 向下搜索
            char c = key[i];
            p = p->children[c - 'a'];
        }
        return p;
    }
    // 定义：向以 node 为根的 Trie 树中插入 key[i..]，返回插入完成后的根节点
    TrieNode *putHelper(TrieNode *node, string &key, V val, int i)
    {
        if (node == NULL)
        {
            // 如果树枝不存在，新建
            node = new TrieNode();
        }
        if (i == key.size())
        {
            // key 的路径已插入完成，将值 val 存入节点
            node->val = val;
            return node;
        }
        char c = key[i];
        // 递归插入子节点，并接收返回值
        node->children[c - 'a'] = putHelper(node->children[c - 'a'], key, val, i + 1);
        return node;
    }

    bool hasKeyWithPatternHelper(TrieNode *node, string &pattern, int i)
    {
        if (node == NULL)
        {
            // 树枝不存在，即匹配失败
            return false;
        }
        if (i == pattern.size())
        {
            // 模式串走到头了，看看匹配到的是否是一个键
            return node->val != NULL;
        }
        char c = pattern[i];
        // 没有遇到通配符
        if (c != '.')
        {
            // 从 node.children[c] 节点开始匹配 pattern[i+1..]
            return hasKeyWithPatternHelper(node->children[c - 'a'], pattern, i + 1);
        }
        // 遇到通配符
        for (char j = 0; j < 26; j++)
        {
            // pattern[i] 可以变化成任意字符，尝试所有可能，只要遇到一个匹配成功就返回
            if (hasKeyWithPatternHelper(node->children[j], pattern, i + 1))
            {
                return true;
            }
        }
        // 都没有匹配
        return false;
    }
};

// TrieSet可直接用TrieMap封装
class TrieSet
{
private:
    // 底层用一个 TrieMap，键就是 TrieSet，值仅仅起到占位的作用
    // 值的类型可以随便设置
    TrieMap<int> map;

public:
    /***** 增 *****/
    // 在集合中添加元素 key
    void add(string key)
    {
        map.put(key, 666);
    }

    // 通配符 . 匹配任意字符，判断集合中是否存在匹配 pattern 的元素
    bool hasKeyWithPattern(string pattern)
    {
        return map.hasKeyWithPattern(pattern);
    }
};
TrieSet* mySet = new TrieSet();
    WordDictionary() {

    }
    
    void addWord(string word) {
        mySet->add(word);
    }
    
    bool search(string word) {
        return mySet->hasKeyWithPattern(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// https://leetcode.cn/problems/replace-words/description/
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieSet* mySet = new TrieSet();
        for (string& s: dictionary) {
            mySet->add(s);
        }
        istringstream iss(sentence);
        string res;
        while(iss) {
            string curr;
            iss >> curr;
            string temp = mySet->shortestPrefixOf(curr);
            res += " ";
            if (temp != "") {
                res += temp;
            } else {
                // 完全没匹配，加入原词即可
                res += curr;
            }
        }
        res.erase(res.begin());
        res.erase(res.end() - 1);
        return res;
    }

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
                children.resize(256);
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
            }
            // 需要一个额外的辅助函数，并接收其返回值
            root = putHelper(root, key, val, NULL);
        }

        /***** 删 *****/
        // 删除键 key 以及对应的值
        // 如何保证不多删除自己？
        // 一个节点要先递归处理子树，然后在后序位置检查自己的val字段和children列表，判断自己是否需要被删除。
        // 在 Map 中删除 key
        void remove(string key)
        {
            if (!containsKey(key))
            {
                return;
            }
            // 递归修改数据结构要接收函数的返回值
            root = removeHelper(root, key, NULL);
            size--;
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

        // 在 Map 的所有键中搜索 query 的最短前缀
        // shortestPrefixOf("themxyz") -> "the"
        string shortestPrefixOf(string query)
        {
            TrieNode *p = root;
            // 从节点 node 开始搜索 key
            for (int i = 0; i < query.size(); i++)
            {
                if (p == NULL)
                {
                    // 无法向下搜索
                    return "";
                }
                if (p->val != NULL)
                {
                    // 找到一个键是 query 的前缀
                    return query.substr(0, i);
                }
                // 向下搜索
                char c = query[i];
                p = p->children[c];
            }
            // 注意别漏掉query本身的检查
            if (p != NULL && p->val != NULL)
            {
                // 如果 query 本身就是一个键
                return query;
            }
            return "";
        }

        // 在 Map 的所有键中搜索 query 的最长前缀
        // longestPrefixOf("themxyz") -> "them"
        string longestPrefixOf(string query)
        {
            TrieNode *p = root;
            // 记录前缀的最大长度
            int max_len = 0;
            // 从节点 node 开始搜索 key
            for (int i = 0; i < query.size(); i++)
            {
                if (p == NULL)
                {
                    // 无法向下搜索
                    return "";
                }
                if (p->val != NULL)
                {
                    max_len = i;
                }
                // 向下搜索
                char c = query[i];
                p = p->children[c];
            }
            if (p != NULL && p->val != NULL)
            {
                // 如果 query 本身就是一个键
                return query;
            }
            return query.substr(0, max_len);
        }

        // 搜索所有前缀为 prefix 的键
        // keysWithPrefix("th") -> ["that", "the", "them"]
        list<string> keysWithPrefix(string prefix)
        {
            list<string> res;
            // 找到匹配 prefix 在 Trie 树中的那个节点
            TrieNode *x = getNode(root, prefix);
            if (x == NULL)
            {
                return res;
            }
            string s = prefix;
            // DFS 遍历以 x 为根的这棵 Trie 树
            traversePrefix(x, s, res);
            return res;
        }

        // 判断是和否存在前缀为 prefix 的键
        // hasKeyWithPrefix("tha") -> true
        // hasKeyWithPrefix("apple") -> false
        bool hasKeyWithPrefix(string prefix)
        {
            return getNode(root, prefix) != NULL;
        }

        // 通配符 . 匹配任意字符，搜索所有匹配的键
        // keysWithPattern("t.a.") -> ["team", "that"]
        list<string> keysWithPattern(string pattern)
        {
            list<string> res;
            string path = "";
            traversePattern(root, path, pattern, NULL, res);
            return res;
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
        // 从节点 node 开始搜索 key，如果存在返回对应节点，否则返回 NULL
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
                p = p->children[c];
            }
            return p;
        }
        // 遍历以 node 节点为根的 Trie 树，找到所有键, DFS
        void traversePrefix(TrieNode *node, string &path, list<string> &res)
        {
            if (!node)
                return;
            if (node->val != NULL)
            {
                res.push_back(path);
            }
            for (char c = 0; c < R; c++)
            {
                // 回溯
                path.push_back(c);
                traversePrefix(node->children[c], path, res);
                path.pop_back();
            }
        }

        // 遍历函数，尝试在「以 node 为根的 Trie 树中」匹配 pattern[i..]
        void traversePattern(TrieNode *node, string &path, string &pattern, int i, list<string> &res)
        {
            if (node == NULL)
            {
                // 树枝不存在，即匹配失败
                return;
            }
            if (i == pattern.size())
            {
                // pattern 匹配完成
                if (node->val != NULL)
                {
                    // 如果这个节点存储着 val，则找到一个匹配的键
                    res.push_back(path);
                }
                return;
            }
            char c = pattern[i];
            if (c == '.')
            {
                // pattern[i] 是通配符，可以变化成任意字符
                // 多叉树（回溯算法）遍历框架
                for (char j = 0; j < R; j++)
                {
                    path.push_back(j);
                    traversePattern(node->children[j], path, pattern, i + 1, res);
                    path.pop_back();
                }
            }
            else
            {
                // pattern[i] 是普通字符 c
                path.push_back(c);
                traversePattern(node->children[c], path, pattern, i + 1, res);
                path.pop_back();
            }
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
                return hasKeyWithPatternHelper(node->children[c], pattern, i + 1);
            }
            // 遇到通配符
            for (int j = 0; j < R; j++)
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
            node->children[c] = putHelper(node->children[c], key, val, i + 1);
            return node;
        }

        // 定义：在以 node 为根的 Trie 树中删除 key[i..]，返回删除后的根节点
        TrieNode *removeHelper(TrieNode *node, string key, int i)
        {
            if (node == NULL)
            {
                return NULL;
            }
            if (i == key.size())
            {
                // 找到了 key 对应的 TrieNode，删除 val
                node->val = NULL;
            }
            else
            {
                char c = key[i];
                // 递归去子树进行删除
                node->children[c] = removeHelper(node->children[c], key, i + 1);
            }
            // 后序位置，递归路径上的节点可能需要被清理
            if (node->val != NULL)
            {
                // 如果该 TrieNode 存储着 val，不需要被清理
                return node;
            }
            // 检查该 TrieNode 是否还有后缀
            for (int c = 0; c < R; c++)
            {
                if (node->children[c] != NULL)
                {
                    // 只要存在一个子节点（后缀树枝），就不需要被清理
                    return node;
                }
            }
            // 既没有存储 val，也没有后缀树枝，则该节点需要被清理
            return NULL;
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

        /***** 删 *****/

        // 从集合中删除元素 key
        void remove(string key)
        {
            map.remove(key);
        }

        /***** 查 *****/

        // 判断元素 key 是否存在集合中
        bool contains(string key)
        {
            return map.containsKey(key);
        }

        // 在集合中寻找 query 的最短前缀
        string shortestPrefixOf(string query)
        {
            return map.shortestPrefixOf(query);
        }

        // 在集合中寻找 query 的最长前缀
        string longestPrefixOf(string query)
        {
            return map.longestPrefixOf(query);
        }

        // 在集合中搜索前缀为 prefix 的所有元素
        list<string> keysWithPrefix(string prefix)
        {
            return map.keysWithPrefix(prefix);
        }

        // 判断集合中是否存在前缀为 prefix 的元素
        bool hasKeyWithPrefix(string prefix)
        {
            return map.hasKeyWithPrefix(prefix);
        }

        // 通配符 . 匹配任意字符，返回集合中匹配 pattern 的所有元素
        list<string> keysWithPattern(string pattern)
        {
            return map.keysWithPattern(pattern);
        }

        // 通配符 . 匹配任意字符，判断集合中是否存在匹配 pattern 的元素
        bool hasKeyWithPattern(string pattern)
        {
            return map.hasKeyWithPattern(pattern);
        }

        // 返回集合中元素的个数
        int size()
        {
            return map.Size();
        }
    };
};
// https://leetcode.cn/problems/alien-dictionary/description/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adjList;
        vector<int> inDegreeVec(26); // 26个字母
        // 这一步不是多余的！所有输入的char我们都要在adjList建立索引，答案里也不会无视某个char
        // 因为count在有、或者没有这个索引的时候，都会返回0！所以会导致少push进queue那些暂未明确字典序但又合法的char
        for (const auto& word : words) {
            for (char c : word) {
                // 如果 c 还未在哈希表的 key 中出现，创建 key，并且初始化它的后继结点列表
                adjList[c] = unordered_set<char>();
            }
        }
        // 相邻两单词比较得出字典序
        for (int i = 0; i < n - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int minLen = min(word1.size(), word2.size());
            for (int j = 0; j < minLen; j++) {
                if (word1[j] != word2[j]) {
                    // 注意不要重复增加入度，所以判断
                    if (adjList[word1[j]].count(word2[j]) == 0) {
                        inDegreeVec[word2[j] - 'a']++;
                        adjList[word1[j]].insert(word2[j]);
                    }
                    break; // 已经字符不相等了，后序的不能继续比对了，无法判断之后的字典序到底啥样
                }
                // 比对到了最后一位，然后发现前面的单词居然更长，违反字典序，返回空
                if (j == minLen - 1 && word1.size() > word2.size()) {
                    return "";
                }
            }
        }
        // 邻接表和入度搞定，开始拓扑遍历
        // 注意char和int的转换
        // 注意判断下这个字母是不是输入的一部分，不一定所有26个字母都在输入里的
        queue<char> q;
        for (int i = 0; i < inDegreeVec.size(); i++) {
            if (inDegreeVec[i] == 0 && adjList.count(i + 'a')) {
                q.push(i + 'a');
            }
        }
        string res;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            res += curr;
            for (char nei : adjList[curr]) {
                inDegreeVec[nei - 'a']--;
                if (inDegreeVec[nei - 'a'] == 0) {
                    q.push(nei);
                }
            }
        }
        if (res.size() == adjList.size()) {
            return res;
        }
        return "";
    }
};
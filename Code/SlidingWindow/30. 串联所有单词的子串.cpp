class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int sLen = s.size();
        int wordsNum = words.size();
        int wordLen = words[0].length();
        int windowLen = wordLen * wordsNum;
        for (int i = 0; i < wordLen; i++) {
            if (i + windowLen > sLen) {
                break;
            }
            unordered_map<string, int> m;
            // 初始窗口，窗口大小=单词大小*单词数量，每次向右滑动一个单词的长度
            // 用一个hashmap来计算窗口与words的单词频度之差，如果为0，说明窗口和words是完全匹配的
            for (int j = 0; j < wordsNum; j++) {
                string word = s.substr(i + j * wordLen, wordLen);
                m[word]++;
            }
            for (string& word : words) {
                m[word]--;
                if(m[word] == 0) {
                    m.erase(word);
                }
            }
            if (m.empty()) {
                res.push_back(i);
            }
            // 窗口更新
            for (int k = i; k + windowLen + wordLen <= sLen; k += wordLen) {
                string left = s.substr(k, wordLen);
                m[left]--;
                if(m[left] == 0) {
                    m.erase(left);
                }
                string right = s.substr(k + windowLen, wordLen);
                m[right]++;
                if(m[right] == 0) {
                    m.erase(right);
                }
                // 注意此刻已经更新了一次窗口，所以+wordLen才是正确的开始index
                if (m.empty()) {
                    res.push_back(k + wordLen);
                }
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/?company_slug=huawei
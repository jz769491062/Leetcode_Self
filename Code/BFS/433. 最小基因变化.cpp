// https://leetcode.cn/problems/minimum-genetic-mutation/description/?orderBy=most_votes
class Solution {
    string items = "ACGT";
    unordered_set<string> myset;
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        myset.insert(startGene);
        for (string& s : bank) {
            myset.insert(s);
        }
        if (!myset.count(endGene)) {
            return -1;
        }
        deque<string> d1, d2;
        d1.push_back(startGene);
        d2.push_back(endGene);
        unordered_map<string, int> m1, m2;
        m1[startGene] = 0;
        m2[endGene] = 0;
        while (!d1.empty() && !d2.empty()) {
            int res = -1;
            if (d1.size() <= d2.size()) {
                res = bfs(d1, m1, m2);
            } else {
                res = bfs(d2, m2, m1);
            }
            if (res != -1) {
                return res;
            }
        }
        return -1;
    }

    int bfs(deque<string>& d, unordered_map<string, int>& cur, unordered_map<string, int>& other) {
        int m = d.size();
        while (m > 0) {
            m--;
            string s = d.front();
            d.pop_front();
            int step = cur[s];
            // 8 positions
            for (int i = 0; i < 8; i++) {
                for (char& c : items) {
                    if (s[i] == c) {
                        continue;
                    }
                    string copy = s;
                    copy[i] = c;
                    if (!myset.count(copy) || cur.count(copy)) {
                        continue;
                    }
                    if (other.count(copy)) {
                        return other[copy] + step + 1;
                    }
                    d.push_back(copy);
                    cur[copy] = step + 1;
                }
            }
        }
        return -1;
    }
};
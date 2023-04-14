class Solution {
    vector<bool> used;
    int res = 0;
public:
    int numTilePossibilities(string tiles) {
        used.resize(tiles.size());
        sort(tiles.begin(), tiles.end());
        string path;
        backtrack(tiles, path, used);
        return res;
    }

    void backtrack(string& tiles, string& path, vector<bool>& used) {
        if (path.size() == tiles.size()) {
            return;
        }
        for (int i = 0; i < tiles.size(); i++) {
            if (!used[i]) {
                if (i >= 1 && !used[i - 1] && tiles[i] == tiles[i - 1]) {
                    continue;
                }
                used[i] = true;
                res++;
                path.push_back(tiles[i]);
                backtrack(tiles, path, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};// https://leetcode.cn/problems/letter-tile-possibilities/description/
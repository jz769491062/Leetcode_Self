class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // Rabin-Karp算法思想：把每个字符抽象成一个数字，把数字作为哈希的key，避免每次substring操作获取子串
        // 每次滑动窗口，如同加入一个最低位数字，并且移除一个最高位数字
        int sz = s.size();
        int* nums = new int[sz];
        memset(nums, 0, sz);
        // ACGT分别编码为0123
        for (int i = 0; i < sz; i++) {
            switch(s[i]) {
                case 'A':
                    nums[i] = 0;
                    break;
                case 'C':
                    nums[i] = 1;
                    break;
                case 'G':
                    nums[i] = 2;
                    break;
                case 'T':
                    nums[i] = 3;
                    break;
            }
        }
        unordered_set<int> seen; // 判断重复出现的哈希值
        unordered_set<string> resSet; // 字符串可能重复出现多次，所以还是要去重一下
        // 数字位数, 窗口大小
        int L = 10;
        // 进制
        int R = 4;
        // 存储 R^(L - 1) 的结果
        int RL = (int) pow(R, L - 1); // RL用于缩小窗口时的R^(L - 1)
        // 维护滑动窗口中字符串的哈希值
        int windowHash = 0;
        // 开始滑动窗口
        int left = 0, right = 0;
        while (right < sz) {
            // 加入右边1位
            windowHash = R * windowHash + nums[right];//注意乘以进制R
            right++;
            if (right - left == L) {
                if (seen.count(windowHash)) {//判断当前字符串出现过没有
                    // 重复出现，加入res
                    resSet.insert(s.substr(left, L));
                } else {
                    seen.insert(windowHash);
                }
                // 缩小窗口，移除最高1位
                windowHash = windowHash - nums[left] * RL;
                left++;
            }
        }
        vector<string> res;
        res.insert(res.end(), resSet.begin(), resSet.end());//把set装进vector
        /* 扩展：如果需要高效把set<类>装进vector的话（如果是基础类型就用上面这行就够了，没区别）
            vector.reserve(set.size());
            for (auto it = set.begin(); it != set.end(); ) {
                vector.push_back(std::move(set.extract(it++).value()));
            }
        */
        return res;
    }
};// https://leetcode.cn/problems/repeated-dna-sequences/description/
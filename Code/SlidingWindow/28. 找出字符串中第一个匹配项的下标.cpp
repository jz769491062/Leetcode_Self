class Solution {
public:
    int strStr(string haystack, string needle) {
        /* Rabin-Karp思路：字符串转换为数字哈希，直接用对应的ASCII码即可
         但是有0-255共256个ASCII码，needlesize ^ (255) 太多了long都装不下
         所以需要求模运算：
         X % Q == (X + Q) % Q
         (X + Y) % Q == (X % Q + Y % Q) % Q
         选一个很大的素数作为Q，降低哈希冲突概率。
         用素数让每次被除后的结果分布均匀。比如拿100当Q，那结果固定为后两位，冲突就很严重了
         哈希冲突概率忽略不计了，Rabin-Karp算法就能降低到O(needle + haystack)
        */
        // 位数, 窗口大小
        int L = needle.size();
        int R = 256; // 只考虑ASCII编码
        long Q = 1658598167; // 大素数
        // R^(L - 1) 的结果
        long RL = 1;
        for (int i = 1; i < L; i++) { // 注意是1~L-1这个范围循环，不断*R
            // 计算过程中不断求模，避免溢出
            RL = (RL * R) % Q;
        }
        // O(L)计算needle对应的哈希值
        long needleHash = 0;
        for (int i = 0; i < L; i++) {
            needleHash = (needleHash * R + needle[i]) % Q; // 记得取模
        }
        // 开始滑窗
        long windowHash = 0;
        int left = 0, right = 0;
        while (right < haystack.size()) {
            windowHash = (windowHash * R + haystack[right]) % Q;
            right++;
            if (right - left == L) {
                if (windowHash == needleHash) {
                    // 注意！hash值相同，但仍然有哈希冲突的可能性
                    // (求模后hash值相同，不代表原始代表的字符串真的相同)
                    // 所以还要检查一下子串是不是真的相等
                    if (needle == haystack.substr(left, L)) {
                        return left;
                    }
                }
                // 缩小窗口
                // X % Q == (X + Q) % Q 是一个模运算法则
                // 因为 windowHash - (txt[left] * RL) % Q 可能是负数
                // 所以额外再加一个 Q，保证 windowHash 不会是负数
                windowHash = ((windowHash - (haystack[left] * RL) % Q) + Q) % Q;
                left++;
            }
        }
        return -1;
    }
};//https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
class Solution {
    using LL = long long;
public:
    vector<LL> GetCandidates(string& s) {
        int n = s.size();
        /* 考虑到以上所有的可能，我们可以给出最终的方案：分别计算出以下每一种可能的方案对应的回文整数，在其中找到与原数最近且不等于原数的数即为答案。

        用原数的前半部分替换后半部分得到的回文整数。
        用原数的前半部分加一后的结果替换后半部分得到的回文整数。
        用原数的前半部分减一后的结果替换后半部分得到的回文整数。
        为防止位数变化导致构造的回文整数错误，因此直接构造999999…999 和 001100…001 作为备选答案
         */
        vector<LL> candidates = {
            (LL)pow(10, n - 1) - 1,
            (LL)pow(10, n) + 1,
        };
        LL firstHalf = stoll(s.substr(0, (n + 1)/2));
        for (int i : {firstHalf - 1, firstHalf, firstHalf + 1}) {
            string prefix = to_string(i);
            // n & 1就是如果是单数就+1，双数不+1，回文的性质
            string candidate = prefix + string(prefix.rbegin() + (n & 1), prefix.rend());
            candidates.push_back(stoll(candidate));
        }
        return candidates;
    }

    string nearestPalindromic(string n) {
        // 构造回文的方法：用其中高位的数字替换低位的数字，12345把5换1,4换2
        // 但是还有2种情况：1 构造回文数字大于原数字，可以减小中间部分来达到最佳结果。99321最佳是99299而不是99399。 2 构造回文数字小于原数字，可以增大中间部分达到最佳结果。12399最佳是12421而不是12321
        // 3 构造回文数字等于原数时，得排除掉这个结果，在其他可能性中寻找结果
        LL selfNumber = stoll(n), ans = -1;
        const vector<LL>& candidates = GetCandidates(n);
        for (LL candidate : candidates) {
            if (candidate != selfNumber) {
                if (ans == -1 ||
                    llabs(candidate - selfNumber) < llabs(ans - selfNumber) ||
                    (llabs(candidate - selfNumber) == llabs(ans - selfNumber) && candidate < ans)) {
                    ans = candidate;
                }
            }
        }
        return to_string(ans);
    }
};// https://leetcode.cn/problems/find-the-closest-palindrome/description/?company_slug=huawei
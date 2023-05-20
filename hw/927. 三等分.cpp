// https://leetcode.cn/problems/three-equal-parts/description/
/*
@可爱抱抱呀
执行用时：1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗：46.3 MB, 在所有 Java 提交中击败了86.49%的用户
2022年7月30日 9:21
*/
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum == 0) return {0, 2};
        if (sum % 3 != 0) return {-1, -1};
        sum /= 3;
        int r = arr.size() - 1, l = 0;
        while (arr[r] == 0) r--;
        int end = r;
        int zero = arr.size() - 1 - r; // 最后一个数末尾0的个数，其他两数的末尾0应该不少
        int count = 0;
        while (count < sum) {
            count += arr[l];
            l++;
        }
        // 此时的l是第一组1的末尾后边
        r = l;
        while (count < sum * 2) {
            count += arr[r];
            r++;
        }
        // 此时的r是第二组1的末尾后边
        // 先验证末尾0是否数量足够：
        for (int i = l; i < l + zero; i++) {
            if (arr[i] == 1) {
                return {-1, -1};
            }
        }
        for (int i = r; i < r + zero; i++) {
            if (arr[i] == 1) {
                return {-1, -1};
            }
        }
        // 再验证其他位是否一致：
        count = 0;
        for (int i = 0; count < sum; i++) {
            if (arr[end - i] != arr[r - 1 - i] || arr[end - i] != arr[l - 1 - i]) {
                return {-1, -1};
            }
            count += arr[end - i];
        }
        return {l + zero - 1, r + zero};
    }
};

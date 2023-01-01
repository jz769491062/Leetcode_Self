class Solution {
public:
    void reverseString(vector<char>& s) {
        //双指针左右两头交换
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};//https://leetcode.cn/problems/reverse-string/description/
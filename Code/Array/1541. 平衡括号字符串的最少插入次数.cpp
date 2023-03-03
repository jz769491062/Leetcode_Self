class Solution {// https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/description/
public:
    int minInsertions(string s) {
        // 注意currInserts是当前需要的插入次数，不是对左括号的需求！
        // 表示的是当前遍历过程中为了配平当前的状态，所需要插入左括号或是右括号的总次数，need表示的是遍历结束后仍需要的右括号数量
        int needRight = 0, currInserts = 0;
        for (char c : s) {
            if (c == '(') {
                needRight += 2;
                //因为右括号数量必须是偶数，所以当遇到左括号时判断need，如果是奇数则添加一个右括号以平衡（表现为res++），添加之后，我们对右的需求减少1个，因此need-- 
// 本质是发生的需求的转移，通过res将对右括号的需求转移到res，可以理解成逻辑上 我们前面部分已经“完全匹配”）--“（））” 把这个测试用例带进去就能理解了
// 确保有两个连续的右括号，如果当前下标的后面的一个字符是右括号，则当前下标和后一个下标是两个连续的右括号，因此将下标加 222，否则就需要在当前位置的后面插入一个右括号，才有两个连续的右括号，因此将插入次数加 111，并将下标加 111
                if (needRight % 2 == 1) {
                    currInserts++;
                    needRight--;
                }
            }
            if (c == ')') {
                needRight--;
                // 右括号过多了
                if (needRight == -1) {
                    // 注意补一个左括号之后，也要补一个右括号了
                    needRight = 1;
                    currInserts++;
                }
            }
        }
        return currInserts + needRight;
    }
};
// JS版本更好理解
var minInsertions = function (s) {
  let rightNeeds = 0;
  let leftNeeds = 0; 
  let rightInsertTimes = 0;
  let leftInsertTimes = 0;

  for (let c of s) {
    if (c === '(') {
      rightNeeds += 2;
      if (rightNeeds % 2 === 1) { // 奇数个
        rightInsertTimes++;
        rightNeeds--;
      }
    }
    if (c === ')') {
      rightNeeds--;
      if (rightNeeds === -1) { // 多了一个右括号
        leftInsertTimes++;
        rightNeeds = 1;
      }
    }
  }
  return rightNeeds +leftNeeds+ rightInsertTimes + leftInsertTimes;
};
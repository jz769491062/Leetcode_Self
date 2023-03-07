class Solution {
    vector<int> res;
public:
    vector<int> pancakeSort(vector<int>& arr) {
        // 1 找到当前最大的饼 2 把大饼放到末尾 3 递归调用n-1范围的烧饼排序
        // 先把饼翻到最上面，然后翻到最下面，就可保证放到末尾
        pSort(arr, arr.size());
        return res;
    }
    void pSort(vector<int>& arr, int n) {
        if (n == 1) return;
            // 寻找最大饼的索引
        int maxCake = 0;
        int maxCakeIndex = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] > maxCake) {
                maxCakeIndex = i;
                maxCake = arr[i];
            }
        }
        reverse(arr, 0, maxCakeIndex); // 翻上去
        res.push_back(maxCakeIndex + 1);
        reverse(arr, 0, n - 1); // 翻下去
        res.push_back(n);
        // 递归
        pSort(arr, n - 1);
    }
    
    void reverse(vector<int>& arr, int i, int j) {
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }

};// https://leetcode.cn/problems/pancake-sorting/description/
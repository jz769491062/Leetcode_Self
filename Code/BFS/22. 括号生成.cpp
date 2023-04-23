class Solution {
public:
struct Node {
    string res;
    int left;
    int right;
    Node(string str, int left, int right) {
        this->res = str;
        this->left = left;
        this->right = right;
    }
};
    vector<string> generateParenthesis(int n) {
        queue<Node*> q;
        q.push(new Node("", n, n));
        vector<string> res;
        while (!q.empty()) {
            Node* curr = q.front();
            int lc = curr->left, rc = curr->right;
            string currRes = curr->res;
            q.pop();
            if (lc == 0 && rc == 0) {
                res.push_back(currRes);
            }
            if (lc > 0) {
                q.push(new Node(currRes + "(", lc - 1, rc));
            }
            // 注意lc < rc
            if (rc > 0 && lc < rc) {
                q.push(new Node(currRes + ")", lc, rc - 1));
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/generate-parentheses/description/
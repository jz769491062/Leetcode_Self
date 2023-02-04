/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traverse(Node* l, Node* r) {
        if (!l || !r) return;//完全二叉树，到NULL层return
        l->next = r;
        // 然后连接：左子树2节点，右子树2节点，左右&右左
        traverse(l->left, l->right);
        traverse(r->left, r->right);
        traverse(l->right, r->left);
    }

    Node* connect(Node* root) {
        // 遍历？可以。
        // 每个节点干什么? 左节点和右节点连起来，如果可能的话还要连接另一子树的子节点
        // 要保存另一子树的子节点……我们不得不同时看两颗子树了，也就是traverse入参左和右。
        if (!root) return NULL;
        traverse(root->left, root->right);
        return root;
    }
};// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/
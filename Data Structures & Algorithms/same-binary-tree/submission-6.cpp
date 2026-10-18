/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        queue<TreeNode*> mq;
        if(p != nullptr) mq.push(p);
        if(q != nullptr) mq.push(q);
        while(!mq.empty()){
            TreeNode* first = mq.front();
            mq.pop();
            if(mq.size() == 0) return false;
            TreeNode* second = mq.front();
            mq.pop();
            if(first->val != second->val) return false;
            if(first->left != nullptr) mq.push(first->left);
            if(second->left != nullptr) mq.push(second->left);
            if(first->right != nullptr) mq.push(first->right);
            if(second->right != nullptr) mq.push(second->right);
            if(first->left != nullptr && second->left == nullptr || first->left == nullptr && second->left != nullptr || first->right != nullptr && second->right == nullptr || first->right == nullptr && second->right != nullptr) return false;
        }
        return true;
    }
};

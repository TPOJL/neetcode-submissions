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
        queue<TreeNode*> mq;
        mq.push(p);
        mq.push(q);
        
        while (!mq.empty()) {
            TreeNode* first = mq.front();
            mq.pop();
            TreeNode* second = mq.front();
            mq.pop();
            
            // If both are null, this branch matches; move to the next pair
            if (!first && !second) continue;
            
            // If one is null or values don't match, trees are different
            if (!first || !second || first->val != second->val) return false;
            
            // Push left children as a pair
            mq.push(first->left);
            mq.push(second->left);
            
            // Push right children as a pair
            mq.push(first->right);
            mq.push(second->right);
        }
        return true;
    }
};

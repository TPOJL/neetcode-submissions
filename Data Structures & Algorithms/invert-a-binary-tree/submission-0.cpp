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

void DFS(TreeNode* root){
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(root->left != nullptr){
        DFS(root->left);
    }
    if(root->right != nullptr){
        DFS(root->right);
    }
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return 0;
        DFS(root);
        return root;
    }
};

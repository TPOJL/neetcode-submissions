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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        
        while (current != nullptr && current->val != key) {
            parent = current;
            if (key < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (current == nullptr) return root;
        
        if (current->left != nullptr && current->right != nullptr) {
            TreeNode* successorParent = current;
            TreeNode* successor = current->right;
            
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            
            current->val = successor->val;
            
            current = successor;
            parent = successorParent;
        }

        TreeNode* child = (current->left != nullptr) ? current->left : current->right;

        if (parent == nullptr) {
            delete current;
            return child;
        }

        if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }

        delete current;
        
        return root;
    }
};
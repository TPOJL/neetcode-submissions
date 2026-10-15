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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* current = root;
        if (root == nullptr) {
            return new TreeNode(val);
        }

        while(true){
            if(val < current->val){
                if(current->left == nullptr){
                    current->left = new TreeNode(val);
                    break;
                }
                current = current->left;
            }else {
                if(current->right == nullptr){
                    current->right = new TreeNode(val);
                    break;
                }
                current = current->right;
            }
        }

        return root;
    }
};
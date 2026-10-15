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
private:
    vector<int> DFS(TreeNode* root, vector<int> &answer){
        TreeNode* child = root;
        if(child->left != nullptr) DFS(child->left, answer);
        answer.push_back(root->val);
        if(child->right != nullptr) DFS(child->right, answer);
        return answer;
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> answer;
        DFS(root, answer);
        return answer;
    }
};
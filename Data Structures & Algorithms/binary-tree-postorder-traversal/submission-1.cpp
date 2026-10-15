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
        if(root->left != nullptr) DFS(root->left, answer);
        if(root->right != nullptr) DFS(root->right, answer);
        answer.push_back(root->val);
        return answer;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> answer;
        DFS(root, answer);
        return answer;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == nullptr) return {};

        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int level_size = q.size();
            vector<int> layer;

            for(int j = 0; j < level_size; j++){
                TreeNode* current = q.front();
                q.pop();

                layer.push_back(current->val);
                if(current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            answer.push_back(layer);
        }
        return answer;
    }
};

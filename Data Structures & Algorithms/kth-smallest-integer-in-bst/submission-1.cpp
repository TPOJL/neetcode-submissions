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
    int dfs(TreeNode* root, int k, int &counter, int &answer){
        if(!root) return false; 

        if(root->left != nullptr) dfs(root->left, k, counter, answer);
        counter++;
        if(counter == k){
            answer = root->val;
            return true;
        }
        return dfs(root->right, k, counter, answer);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int answer = 0;
        dfs(root, k, counter, answer);
        return answer;
    }
};

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
    int result = 0;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        root->val += dfs(root->left);
        root->val += dfs(root->right);
        result += abs(root->val - 1);
        return root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        int noNeed = dfs(root);
        return result;
    }
};
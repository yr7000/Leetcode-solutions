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
    int result = INT_MIN;
    
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        result = max({result,root->val+max({0,l,r,l+r})});
        return root->val + max({0,l,r});
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }
};
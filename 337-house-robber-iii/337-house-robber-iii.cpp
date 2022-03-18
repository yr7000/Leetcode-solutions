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
    
    unordered_map<TreeNode*,int> dp;
    
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        
        if(dp.count(root)) return dp[root];
        
        int left_left_robbery = root->left ? rob(root->left->left) : 0;
        int left_right_robbery = root->left ? rob(root->left->right) : 0;
        int right_left_robbery = root->right ? rob(root->right->left) : 0;
        int right_right_robbery = root->right ? rob(root->right->right) : 0;
        
        int choise1 = root->val + left_left_robbery + left_right_robbery + right_left_robbery + right_right_robbery;
        int choise2 = rob(root->left) + rob(root->right);
        
        return dp[root] = max(choise1,choise2);
    }
};
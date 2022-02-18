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
# define mod 1000000007
class Solution {
public:
    long int result = 0, totalSum = 0;
    long int dfs(TreeNode* root){
        if(root==NULL) return 0;
        long int currentSum = root->val + dfs(root->right) + dfs(root->left);
        result = max(result,(currentSum * (totalSum-currentSum)));
        return currentSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);
        dfs(root);
        return result%(1000000007);
    }
};